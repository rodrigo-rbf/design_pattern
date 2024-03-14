# Biblioteca de trainamento
Caso não tenha feito, abra a pasta desta biblioteca pelo VS Code e abra um novo terminal pelo VS Code (**Terminal > New Terminal**) e acesse, nele, a pasta da biblioteca (`cd ~/Codebase/CLI/Training`). Todos os comandos deste guia pressupõe que o terminal está aberto neste diretório.

## Hello World
Na pasta *test*, há o arquivo *hello_world.cpp*, que será a primeira aplicação há ser executada. Para configurar e compilar a biblioteca, execute:

```
./configure
make
```

O comando `./configure` deve ser executado sempre que uma biblioteca é clonada, ou se um arquivo for adicionado, deletado ou renomeado. O comando `make` de fato compila a biblioteca e suas aplicações.

Após a compilação, os arquivos binários (executáveis) estarão localizados nas pastas *bin* (aplicações geradas a partir dos .cpp da pasta *app/*) e *bin_test* (testes e exemplos gerados a partir dos .cpp da pasta *test/*). 

Para executar os binários contidos em *bin* ou *bin_test*, basta digitar o caminho do terminal. Assim, rode a primeira aplicação com `./bin_test/hello_world`.

>No arquivo *inc/types.hpp*, crie uma classe com o nome *Hello_word*, e declare o contrutor e o destrutor. Em *src/types.cpp*, defina o construtor e o destrutor de forma que as mensagens "Hello World!" e "Goodbye World" sejam impressas. Em *hello_world.cpp*, retire o print existente e instancie a classe *Hello_world*. Recompile o código e execute.

## Exercício 1: Utils
Abra o arquivo *test/test_utils.cpp*. Este arquivo apresenta uma estrutura básica padrão para aplicações e testes. Inicialmente, perceba a inclusão de arquivos da biblioteca **Utils** (`#include <utils/log.hpp`) e a função `void loop(Options options)`, que conterá o código da aplicação/teste.

### utils/log.hpp
As funções de *log* permitem a impressão de mensagens no terminal com diversas informações que auxiliam no *debug* do código, como data-hora, arquivo e linha. Para consultar como usá-las, verifique o arquivo *test_log.cpp* da biblioteca *utils*.
>Na função `loop`, imprima um *log* em nível de *info* com a mensagem "Início do test_utils" (utilize a variável `program_invocation_short_name`). Observe que, na execução, a função de *log* expressa a hora e nível da mensagem, além da função, arquivo e linha que a originou.

### utils/arguments.hpp
A classe *Arguments* encapsula o uso de opções por linha de comando. Por exemplo, a opção `-h` imprime o *help* da aplicação.
>Inclua o arquivo *arguments.hpp* da biblioteca *utils*, e descomente as linhas referentes a classe Arguments na função `main`. Compile, e execute a aplicação com a opção `-h`.

Como não personalizamos as oções do teste, a mensagem de *help* apresenta, apenas, as opções que todas as aplicações que utilizam a classe Arguments possuem (*help* e comfiguração do log). Como teste, execute o teste alterando o nível de verbosidade para *warning* (`-v warning`), e observe que a mensagem "Início do test_utils" não é impressa no terminal. Assim, é possível alterar a verbosidade do log da aplicação sem recompilar.

Normalmente, as opções recebidas por linha de comando modificam/preenchem variáveis contidas da estrutura *Options*, declarada no ínicio do código.
>Acrescente um booleano `flag_print` à estrutura *Options* com valor `false` e acrescente a linha `arguments.add_optional('p',"print", "prints to terminal at start", options.flag_print);` após a declaração da variável `arguments`. Modifique o `log_info()` dentro da função `loop` para só imprimir no terminal caso `options.flag_print` seja `true`. Observe, agora, que a mensagem "Início do test_utils" só é impressa caso o teste seja executado com a opção `-p`.

Há várias formas de receber e tratar argumentos por linha de comando. Sempre que necessário, consulte o *test_arguments.cpp*.
>Utilizando a função `add_optional_callback` da classe *Arguments*, modifique a aplicação para que imprima a mensagem de início caso seja executada com a opção `-p`, da mesma forma que antes, porém sem necessidade de declarar a variável `flag_print`.

>Receba, como argumento obrigatório (`add_mandatory`), o caminho para um arquivo de texto qualquer (Ex.: *~/Codebase/CLI/Training/readme.md*) e faça, na função `loop`, com que o teste imprima no terminal o conteúdo do arquivo. Dica: utilize a classe *ifstream* da biblioteca padrão do C++.