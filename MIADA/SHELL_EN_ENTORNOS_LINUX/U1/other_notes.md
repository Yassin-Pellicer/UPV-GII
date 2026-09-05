# Usuarios y grupos en Linux

La mayoría de estos comandos necesitan permisos de administrador. Se pueden
ejecutar como `root` o anteponiendo `sudo`.

## Consultar el usuario actual

```bash
whoami                 # muestra el nombre del usuario actual
id                     # muestra UID, GID y grupos del usuario
groups                 # muestra los grupos del usuario actual
groups nombre_usuario  # muestra los grupos de otro usuario
```

## Listar usuarios

Los usuarios locales se almacenan normalmente en `/etc/passwd`. Es preferible
usar `getent`, porque también consulta otras fuentes configuradas en el sistema.

```bash
getent passwd                       # lista todos los usuarios
getent passwd | cut -d: -f1         # muestra solo los nombres
getent passwd nombre_usuario        # consulta un usuario concreto
```

Cada línea de `/etc/passwd` tiene este formato:

```text
nombre:x:UID:GID:comentario:directorio_personal:shell
```

Para listar normalmente solo las cuentas humanas, se pueden filtrar los UID,
aunque el intervalo depende de la distribución:

```bash
awk -F: '$3 >= 1000 { print $1 }' /etc/passwd
```

## Crear usuarios

`useradd` crea la cuenta. La opción `-m` crea el directorio personal y `-s`
establece el shell de inicio.

```bash
sudo useradd -m -s /bin/bash ana
sudo passwd ana
```

En sistemas Debian y Ubuntu también se puede usar `adduser`, que ofrece un
asistente más sencillo:

```bash
sudo adduser ana
```

Comprobar la cuenta creada:

```bash
id ana
getent passwd ana
```

## Listar y crear grupos

Los grupos se pueden consultar en `/etc/group` o mediante `getent`:

```bash
getent group                       # lista todos los grupos
getent group nombre_grupo          # consulta un grupo concreto
getent group | cut -d: -f1         # muestra solo los nombres
```

Crear un grupo nuevo:

```bash
sudo groupadd desarrollo
```

Ver los miembros de un grupo:

```bash
getent group desarrollo
```

## Añadir un usuario a un grupo secundario

La forma habitual es:

```bash
sudo usermod -aG desarrollo ana
```

- `-G desarrollo`: indica los grupos secundarios.
- `-a`: añade el grupo sin quitar los grupos secundarios actuales.

También se puede usar `gpasswd`:

```bash
sudo gpasswd -a ana desarrollo
```

> Es importante usar `-a` con `-G`. `usermod -G desarrollo ana` reemplaza la
> lista de grupos secundarios de `ana` y puede quitar permisos que ya tenía.

El cambio suele aplicarse al iniciar una nueva sesión. Para cambiar de grupo
en una shell concreta, se puede usar:

```bash
newgrp desarrollo
```

Comprobar el resultado:

```bash
id ana
groups ana
getent group desarrollo
```

## Cambiar el grupo primario

Cada usuario tiene un grupo primario. Para cambiarlo:

```bash
sudo usermod -g desarrollo ana
```

La opción `-g` cambia el grupo primario; no debe confundirse con `-G`, que
gestiona los grupos secundarios.

## Quitar un usuario de un grupo

```bash
sudo gpasswd -d ana desarrollo
```

Otra opción equivalente es volver a indicar todos los grupos secundarios que
debe conservar el usuario:

```bash
sudo usermod -G grupo1,grupo2 ana
```

En este último caso no se usa `-a` porque se está definiendo la lista completa.

## Eliminar usuarios y grupos

```bash
sudo userdel ana       # elimina la cuenta, pero conserva su directorio personal
sudo userdel -r ana    # elimina la cuenta y su directorio personal
sudo groupdel desarrollo
```

Antes de eliminar un grupo, hay que comprobar que no sea el grupo primario de
algún usuario:

```bash
getent passwd | awk -F: '$4 == 1002 { print $1 }'
```

El número `1002` del ejemplo es el GID del grupo que se quiere comprobar.

## Resumen rápido

| Acción | Comando |
| --- | --- |
| Ver usuario actual | `whoami` |
| Ver UID, GID y grupos | `id usuario` |
| Listar usuarios | `getent passwd` |
| Crear usuario | `sudo useradd -m usuario` |
| Cambiar contraseña | `sudo passwd usuario` |
| Listar grupos | `getent group` |
| Crear grupo | `sudo groupadd grupo` |
| Añadir usuario a grupo | `sudo usermod -aG grupo usuario` |
| Cambiar grupo primario | `sudo usermod -g grupo usuario` |
| Quitar usuario de grupo | `sudo gpasswd -d usuario grupo` |
| Eliminar usuario | `sudo userdel -r usuario` |
