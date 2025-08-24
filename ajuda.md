Procure abaixo a seção correspondente ao seu ambiente Windows. Caso já possua uma instalação linux, veja a seção na sobre **WSL** como instalar os pacotes e testar seu ambiente a partir do passo 3.

## MSYS2/MinGW
Adaptação de https://medium.com/swlh/setting-opengl-for-windows-d0b45062caf

### Passo 1: instalar o MSYS2
Pegar o instalador em https://www.msys2.org/ e em seguida rodar o comando abaixo na shell, atualizando a instalação duas vezes
>$ pacman -Syu

Se a janela da shell fechar, entre novamente nela escolhendo a opção de menu **MSYS2 MINGW64** para refazer o comando abaixo
>$ pacman -Syu

### Passo 2: instalar os pacotes de desenvolvimento
>$ pacman -S base-devel man mingw-w64-x86_64-toolchain mingw-w64-x86_64-freeglut

### Passo 3: testar o ambiente gerando o executavel
> $ gcc -o hello hellogl.c -lopengl32 -lglu32 -lfreeglut
$ ./hello

### Passo 4 (opcional): instalar pacotes adicionais
>$ pacman -S mingw-w64-x86_64-glfw

## Cygwin
### Passo 1: executar o instalador do cygwin
Visite https://cygwin.com/install.html ou pegue o instalador em https://cygwin.com/setup-x86_64.exe e o execute em seguida

### Passo 2: selecionar os pacotes de seu ambiente
Durante a instalação, certifique-se de que os pacotes abaixo foram selecionados. Caso necessário, execute novamente o passo anterior para atualizar a instalação de pacotes de seu ambiente.
>https://cygwin.com/packages/summary/gcc-core.html
https://cygwin.com/packages/summary/libGL-devel.html
https://cygwin.com/packages/summary/libGLU-devel.html
https://cygwin.com/packages/summary/libglut-devel.html
https://cygwin.com/packages/summary/xinit.html

### Passo 3: iniciar o servidor X do cygwin
* Opção 1: no menu iniciar, executar **Cygwin-X / XWin Server**. Você pode verificar que um servidor X está ativo pelo comando abaixo na shell do cygwin.
>$ ps aux | grep XWin

ou
* Opção 2: na shell Cygwin, executar o comando abaixo para usar iniciar um servidor e cliente X do cygwin ao mesmo tempo.
>$ xinit

### Passo 4: testar o ambiente gerando o executavel 
>$ gcc -o hello hellogl.c -lGL -lGLU -lglut
$ DISPLAY=:0 ./hello

O uso da variável DISPLAY só é necessário quando da execução a partir da shell inicial do cygwin. Ela pode ser definida no seu arquivo .bash_profile no diretório $HOME com o comando export.
>$ echo export DISPLAY=:0 >> ~/.bash_profile


## Windows Subsystem for Linux (WSL)
Adaptação de https://learn.microsoft.com/pt-br/windows/wsl/install. Leia a documentação completa caso você não obtenha os resultados esperados de qualquer um dos passos abaixo.

### Passo 1: baixar o instalador
Algumas instalações de Windows já vem com o executável do **WSL** instalado. Você pode verificar se já possui este executável verificando a existência do arquivo _C:\Windows\System32\wsl.exe_ no Windows Explorer ou em alguma shell como PowerShell ou DOS com o comando abaixo:
>C:\path\to\\> dir C:\Windows\System32\wsl.exe

Caso não possua este executável, pegue o instalador do **WSL** em https://github.com/microsoft/WSL/releases e o execute em sua máquina logo em seguida.

### Passo 2: instalar uma distribuição linux dentro do WSL
Abra o PowerShell com privilégios de administrador e em seguida execute o comando abaixo
>C:\path\to\\> wsl.exe --list --online

Este comando oferecerá a lista de distribuições linux possíveis de serem instaladas. Nossa sugestão é que você opte pela instalação de Ubuntu LTS mais recente (opção default). Porém, você pode optar por outra distribuição caso tenha maior familiariedade ou preferência de uso. Tenha em mente que a mudança da distribuição pode impactar no passo seguinte, mais especificamente os nomes dos pacotes a serem instalados. Quando a instalação concluir, o instalador pedirá para você criar um usuário e senha para este sistema e esta senha será a sua senha de _sudo_. Logo em seguida você será redirecionado para uma shell de linux no novo sistema recém instalado.
>C:\path\to\\> wsl.exe --install [-d Distro]

### Passo 3: instalar o ambiente de desenvolvimento e bibliotecas necessárias
Caso tenha escolhido uma versão de Ubuntu, como sugerido anteriormente, o comando abaixo será o suficiente para instalar todos os pacotes necessários. Caso tenha optado por outra distribuição, você deve descobrir qual o nome do pacote que contém as bibliotecas de desenvolvimento do FreeGLUT e quais os pacotes necessários para se instalar o ambiente de desenvolvimento mínimo (gcc, g++, make, etc)
>$ sudo apt install build-essential freeglut3-dev

É recomendável também atualizar os pacotes da distribuição recém instalada tal como na sequência abaixo:
>$ sudo apt update
$ sudo apt upgrade

### Passo 4: testar o ambiente de desenvolvimento
>$ gcc -o hello hellogl.c -lGL -lGLU -lglut
$ ./hello

Para ter acesso ao seu diretório corrente na shell, digite o comando abaixo. Ele irá abrir o Windows Explorer no diretório de sua shell e isto será útil para copiar o arquivo fonte.
>$ explorer.exe .

## MS/Visual Studio
Existem pacotes de GLUT/FreeGLUT instaláveis dentro do MS Visual Studio Community 2022. Pode ser útil para aqueles que optarem por usar esta ferramenta. Eventualmente, qualquer um dos pacotes abaixo, pode ser usado.
>https://www.nuget.org/packages/nupengl.core
https://www.nuget.org/packages/freeglut.3.0.0.v140

Você pode acessar o link abaixo para ver como instalar um destes pacotes. DICA: Veja que o código testado não possui os cabeçalhos *<GL/gl.h>* nem *<GL/glu.h>*
>https://www.youtube.com/watch?v=PeeyWLzRWGg
