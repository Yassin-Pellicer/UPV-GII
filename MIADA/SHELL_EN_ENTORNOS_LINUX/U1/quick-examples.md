## Gestión de trabajos en Bash

Estos comandos permiten controlar los trabajos ejecutados desde el shell:

- `fg`: lleva un trabajo al primer plano.
- `bg`: reanuda un trabajo detenido en segundo plano.
- `jobs`: muestra los trabajos activos o detenidos del shell actual.
- `disown`: desvincula un trabajo del shell para que no reciba sus señales.

### Ejemplo

`Ctrl+Z` detiene temporalmente el proceso que se está ejecutando en primer plano.
Después podemos consultar su estado, llevarlo al primer plano o reanudarlo en
segundo plano:

```bash
$ sleep 60
^Z
[1]+  Stopped                 sleep 60

$ jobs
[1]+  Stopped                 sleep 60

$ fg 1
sleep 60
^Z
[1]+  Stopped                 sleep 60

$ bg 1
[1]+ sleep 60 &
```
