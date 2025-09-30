# Construção dos executáveis

Existem dois exemplos de programas que utilizam uma dupla de _shaders_ (vértice e fragmento) neste diretório. Ambos, quando executados, deverão mostrar um triângulo cujos vértices foram coloridos com as componentes básicas do sistema RGB, realizando a transição de cor de modo suave. Para facilitar a construção destes programas, foi adicionado neste diretório um arquivo _Makefile_ que compilará os arquivos necessários e construirá o executável final. O primeiro exemplo mostrado usa uma dupla de _shaders_ escrita em modo __core__ e que usa a biblioteca _GLEW_ para carregar as extensões necessárias. Os fontes dos _shaders_ usados neste exemplo podem ser encontrados no diretórios _core_. Certifique-se que você possui o pacote _libglew-dev_ instalado ou que a biblioteca esteja disponível por outros meios, do contrário não será possível gerar o executável. A sua geração pode ser feita como mostra o comando abaixo.
```
$ make coreglew
```

Existe uma segunda versão do mesmo programa que carrega as extensões necessárias usando a biblioteca _GLAD_. Neste exemplo, os fontes dos _shaders_ foram escritos em modo __compatibility__, usando a primeira versão de _GLSL_. Para construir este executável, você deve primeiro obter a versão de _GLAD_ para seu sistema indo ao endereço https://glad.dav1d.de/ e preenchendo o formulário que irá lhe redirecionar para a página que contém o arquivo **glad.zip**. Preencha os dados deste formulário com a versão de _OpenGL_ disponível em seu sistema no campo _API gl_ e não se esqueça de adicionar todas as extensões que estiverem disponíveis na caixa de seleção à esquerda, passando-as para a caixa à direita. Crie o subdiretório _glad_ no diretório dos fontes e descompacte o arquivo zip nele. Em seguida, você deve compilar o arquivo _glad.c_ antes de construir o executável, como mostrado abaixo.
```
$ unzip glad.zip -d glad
$ cd glad
$ gcc -c src/glad.c -Iinclude -o glad.o
$ cd ..
```
 
Com o arquivo _glad.o_ disponível, é fácil gerar o executável deste exemplo com o comando _make_ abaixo.
```
$ make compatglad
```

Caso haja necessidade, altere o arquivo _Makefile_ para tornar as configurações de sua compilação mais adequadas ao seu ambiente.
