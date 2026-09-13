(() => {
  "use strict";

  const charts = {};
  const rendered = { companies: false, sectors: false, winners: false, evolution: false };
  const colors = {
    blue: "#2563eb",
    blueSoft: "rgba(37, 99, 235, 0.72)",
    green: "#059669",
    greenSoft: "rgba(5, 150, 105, 0.18)",
    grid: "rgba(148, 163, 184, 0.25)"
  };

  const text = (element) => element ? element.textContent.trim() : "";
  const normalize = (value) => value.normalize("NFD").replace(/[\u0300-\u036f]/g, "").toLowerCase();

  function parseNumber(value) {
    let number = String(value || "").replace(/[^0-9,.-]/g, "");
    if (!number) return NaN;

    const commas = (number.match(/,/g) || []).length;
    const dots = (number.match(/\./g) || []).length;

    if (commas && dots) {
      const decimalMark = number.lastIndexOf(",") > number.lastIndexOf(".") ? "," : ".";
      const decimalLength = number.length - number.lastIndexOf(decimalMark) - 1;
      if (decimalLength <= 2) {
        const thousandsMark = decimalMark === "," ? /\./g : /,/g;
        number = number.replace(thousandsMark, "").replace(decimalMark, ".");
      } else {
        number = number.replace(/[,.]/g, "");
      }
    } else if (commas) {
      number = commas > 1 || /,\d{3}$/.test(number) ? number.replace(/,/g, "") : number.replace(",", ".");
    } else if (dots > 1 || (dots === 1 && /\.\d{3}$/.test(number))) {
      number = number.replace(/\./g, "");
    }

    return Number(number);
  }

  function compactCurrency(value) {
    return new Intl.NumberFormat("es-ES", {
      notation: "compact",
      maximumFractionDigits: 2
    }).format(value) + " $​";
  }

  const commonOptions = {
    responsive: true,
    maintainAspectRatio: false,
    animation: { duration: 450 },
    plugins: {
      legend: { display: false },
      tooltip: {
        callbacks: {
          label: (context) => `${context.dataset.label}: ${compactCurrency(context.parsed.x ?? context.parsed.y)}`
        }
      }
    }
  };

  const pageSize = 20;
  const padRank = value => String(value).padStart(3, "0");
  const rankings = {};

  function renderRanking(key, rows, cardId, canvasId, label, format, green = false) {
    if (!rows.length) return;
    if (!rankings[key]) {
      const pager = document.getElementById(`${key}Pagination`);
      const previous = pager.querySelector(".ranking-previous");
      const next = pager.querySelector(".ranking-next");
      const status = pager.querySelector(".ranking-status");
      const state = rankings[key] = { page: 0 };
      state.update = () => {
        const start = state.page * pageSize;
        const visible = rows.slice(start, start + pageSize);
        rows.forEach((row, index) => {
          row.element.hidden = index < start || index >= start + pageSize;
        });
        previous.disabled = start === 0;
        next.disabled = start + pageSize >= rows.length;
        status.textContent = `${padRank(start + 1)}–${padRank(start + visible.length)} de ${padRank(rows.length)}`;
        if (!window.Chart) return;
        document.getElementById(cardId).hidden = false;
        document.querySelector(`#${cardId} .chart-canvas`).style.height = `${Math.max(320, visible.length * 34)}px`;
        if (charts[key]) {
          charts[key].data.labels = visible.map((row, index) => `${start + index + 1}. ${row.label}`);
          charts[key].data.datasets[0].data = visible.map(row => row.value);
          charts[key].update();
        } else {
          charts[key] = new Chart(document.getElementById(canvasId), {
            type: "bar",
            data: {
              labels: visible.map((row, index) => `${start + index + 1}. ${row.label}`),
              datasets: [{ label, data: visible.map(row => row.value), backgroundColor: green ? colors.greenSoft : colors.blueSoft, borderColor: green ? colors.green : colors.blue, borderWidth: 1 }]
            },
            options: {
              ...commonOptions,
              indexAxis: "y",
              plugins: {
                legend: { display: false },
                tooltip: { callbacks: { label: context => `${label}: ${format(context.parsed.x)}` } }
              },
              scales: {
                x: { beginAtZero: true, grid: { color: colors.grid }, ticks: { callback: format } },
                y: { grid: { display: false }, ticks: { autoSkip: false } }
              }
            }
          });
        }
      };
      previous.addEventListener("click", () => {
        if (state.page > 0) { state.page--; state.update(); }
      });
      next.addEventListener("click", () => {
        if ((state.page + 1) * pageSize < rows.length) { state.page++; state.update(); }
      });
      pager.hidden = false;
      state.update();
    } else if (!charts[key] && window.Chart) {
      rankings[key].update();
    }
    rendered[key] = Boolean(charts[key]);
  }

  function renderCompanyChart() {
    if (rendered.companies) return;
    const rows = [...document.querySelectorAll("#topMarketCapCompanies tr")]
      .map(row => {
        const cells = row.querySelectorAll("td");
        return { element: row, label: text(cells[3]) || text(cells[2]), value: parseNumber(text(cells[1])) };
      }).filter(row => Number.isFinite(row.value))
      .sort((a, b) => b.value - a.value);
    renderRanking("companies", rows, "companyChartCard", "companyMarketCapChart", "Capitalización bursátil", compactCurrency);
  }

  function renderWinnersChart() {
    if (rendered.winners) return;
    const rows = [...document.querySelectorAll("#topMarketWinners tr")]
      .map(row => {
        const cells = row.querySelectorAll("td");
        return { element: row, label: text(cells[2]) || text(cells[1]), value: parseNumber(text(cells[5])) };
      }).filter(row => Number.isFinite(row.value))
      .sort((a, b) => a.value - b.value);
    const percentage = value => new Intl.NumberFormat("es-ES", { maximumFractionDigits: 2 }).format(value) + " %";
    renderRanking("winners", rows, "winnersChartCard", "winnersChart", "Distancia al máximo de 52 semanas", percentage);
  }

  function sectorRowsFromSingleTable(container) {
    const tables = [...container.querySelectorAll("table")];
    if (tables.length !== 1) return [];
    const table = tables[0];
    const headers = [...table.querySelectorAll("thead tr:last-child th")].map((cell) => normalize(text(cell)));
    const sectorIndex = headers.findIndex((heading) => /sector/.test(heading));
    const capIndex = headers.findIndex((heading) => /capitalizacion|market cap/.test(heading) && !/diferencia/.test(heading));
    if (sectorIndex < 0 || capIndex < 0) return [];
    return [...table.querySelectorAll("tbody tr")].map((row) => {
      const cells = row.querySelectorAll("td");
      return { element: row, label: text(cells[sectorIndex]), value: parseNumber(text(cells[capIndex])) };
    });
  }

  function sectorRowsFromBlocks(container) {
    return [...container.querySelectorAll(".sector-table")].map((block) => {
      const label = text(block.querySelector(".table-header, .table-title"));
      const totalElement = block.querySelector(".table-row-total");
      let value = parseNumber(text(totalElement));
      if (!Number.isFinite(value)) {
        const headerCells = [...block.querySelectorAll("thead tr:last-child th")].map((cell) => normalize(text(cell)));
        const capIndex = headerCells.findIndex((heading) => /capitalizacion|market cap/.test(heading) && !/diferencia/.test(heading));
        if (capIndex >= 0) {
          value = [...block.querySelectorAll("tbody tr")].reduce((sum, row) => {
            const cellValue = parseNumber(text(row.querySelectorAll("td")[capIndex]));
            return sum + (Number.isFinite(cellValue) ? cellValue : 0);
          }, 0);
        }
      }
      return { element: block, label: label.replace(/^\d+\s*[|.–-]?\s*/, ""), value };
    });
  }

  function renderSectorChart() {
    if (rendered.sectors) return;
    const container = document.getElementById("sectorRankingData");
    let rows = sectorRowsFromSingleTable(container);
    if (!rows.length) rows = sectorRowsFromBlocks(container);
    rows = rows.filter((item) => item.label && Number.isFinite(item.value) && item.value > 0).sort((a, b) => b.value - a.value);
    renderRanking("sectors", rows, "sectorChartCard", "sectorMarketCapChart", "Capitalización bursátil", compactCurrency, true);
  }

  function readEvolutionSeries() {
    return [...document.querySelectorAll("#evolutionData table")].map((table, index) => {
      const title = text(table.querySelector(".table-title")) || `Compañía ${index + 1}`;
      const headers = [...table.querySelectorAll("thead tr:last-child th")].map((cell) => normalize(text(cell)));
      const dateIndex = headers.findIndex((heading) => /fecha|date/.test(heading));
      const priceIndex = headers.findIndex((heading) => /precio|price/.test(heading) && !/diferencia|difference/.test(heading));
      const capIndex = headers.findIndex((heading) => /capitalizacion|market cap/.test(heading) && !/diferencia|difference/.test(heading));
      if (dateIndex < 0 || priceIndex < 0 || capIndex < 0) return null;

      const points = [...table.querySelectorAll("tbody tr")].map((row) => {
        const cells = row.querySelectorAll("td");
        return {
          date: text(cells[dateIndex]),
          price: parseNumber(text(cells[priceIndex])),
          marketCap: parseNumber(text(cells[capIndex]))
        };
      }).filter((point) => point.date && Number.isFinite(point.price) && Number.isFinite(point.marketCap));
      return points.length ? { title, points } : null;
    }).filter(Boolean);
  }

  function drawEvolution(series) {
    if (charts.evolution) charts.evolution.destroy();
    charts.evolution = new Chart(document.getElementById("evolutionChart"), {
      type: "line",
      data: {
        labels: series.points.map((point) => point.date),
        datasets: [
          { label: "Precio de la acción", data: series.points.map((point) => point.price), yAxisID: "price", borderColor: colors.blue, backgroundColor: colors.blueSoft, pointRadius: 3, tension: 0.2 },
          { label: "Capitalización bursátil", data: series.points.map((point) => point.marketCap), yAxisID: "marketCap", borderColor: colors.green, backgroundColor: colors.greenSoft, pointRadius: 3, tension: 0.2 }
        ]
      },
      options: {
        responsive: true,
        maintainAspectRatio: false,
        interaction: { mode: "index", intersect: false },
        plugins: {
          legend: { display: true, position: "bottom" },
          tooltip: {
            callbacks: {
              label: (context) => context.dataset.yAxisID === "price"
                ? `${context.dataset.label}: ${new Intl.NumberFormat("es-ES", { style: "currency", currency: "USD" }).format(context.parsed.y)}`
                : `${context.dataset.label}: ${compactCurrency(context.parsed.y)}`
            }
          }
        },
        scales: {
          x: { grid: { color: colors.grid } },
          price: { type: "linear", position: "left", title: { display: true, text: "Precio ($)" }, grid: { color: colors.grid } },
          marketCap: { type: "linear", position: "right", title: { display: true, text: "Capitalización ($)" }, grid: { drawOnChartArea: false }, ticks: { callback: compactCurrency } }
        }
      }
    });
  }

  function renderEvolutionChart() {
    if (rendered.evolution || !window.Chart) return;
    const series = readEvolutionSeries();
    if (!series.length) return;
    const select = document.getElementById("evolutionCompanySelect");
    series.forEach((item, index) => select.add(new Option(item.title, index)));
    select.addEventListener("change", () => drawEvolution(series[Number(select.value)]));
    document.getElementById("evolutionChartCard").hidden = false;
    drawEvolution(series[0]);
    rendered.evolution = true;
  }

  function fixTableWidths() {
    document.querySelectorAll('[role="tabpanel"]:not([hidden])').forEach(panel => {
      const tables = [...panel.querySelectorAll("table")];
      const reference = tables.find(table => !table.dataset.fixedColumns);
      if (!reference) return;
      const headers = [...reference.querySelectorAll("thead tr:last-child th")];
      const widths = headers.map(header => header.getBoundingClientRect().width);
      const total = widths.reduce((sum, width) => sum + width, 0);
      if (!total) return;
      tables.forEach(table => {
        if (table.dataset.fixedColumns) return;
        const columns = document.createElement("colgroup");
        widths.forEach(width => {
          const column = document.createElement("col");
          column.style.width = `${width / total * 100}%`;
          columns.append(column);
        });
        table.prepend(columns);
        table.dataset.fixedColumns = "true";
      });
    });
  }

  function renderCharts() {
    fixTableWidths();
    if (!document.getElementById("analysis-companies").hidden) renderCompanyChart();
    if (!document.getElementById("analysis-sectors").hidden) renderSectorChart();
    if (!document.getElementById("analysis-winners").hidden) renderWinnersChart();
    if (!document.getElementById("analysis-evolution").hidden) renderEvolutionChart();
  }

  function initializeTabs() {
    const tabs = [...document.querySelectorAll('.analysis-tabs [role="tab"]')];

    function activateTab(selected) {
      tabs.forEach((tab) => {
        const active = tab === selected;
        tab.setAttribute("aria-selected", String(active));
        tab.tabIndex = active ? 0 : -1;
        document.getElementById(tab.getAttribute("aria-controls")).hidden = !active;
      });
      renderCharts();
      Object.values(charts).forEach((chart) => chart.resize());
    }

    tabs.forEach((tab, index) => {
      tab.addEventListener("click", () => activateTab(tab));
      tab.addEventListener("keydown", (event) => {
        let next;
        if (event.key === "ArrowRight") next = (index + 1) % tabs.length;
        else if (event.key === "ArrowLeft") next = (index - 1 + tabs.length) % tabs.length;
        else if (event.key === "Home") next = 0;
        else if (event.key === "End") next = tabs.length - 1;
        else return;
        event.preventDefault();
        activateTab(tabs[next]);
        tabs[next].focus();
      });
    });
    renderCharts();
  }

  if (document.readyState === "loading") {
    document.addEventListener("DOMContentLoaded", initializeTabs, { once: true });
  } else {
    initializeTabs();
  }
  [300, 1000, 2500].forEach((delay) => setTimeout(renderCharts, delay));
})();
