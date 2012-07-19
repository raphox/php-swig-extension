php-swig-extension
==================

Código, exemplos e informações de como se gerar uma extensão (.so) para servidores PHP com base em códigos em C++ utilizando o Swig.

Arquivos:
---------

- hello.i   # Pseudo código (quase um HEADER, veja a documentação aqui http://www.swig.org/Doc2.0/SWIGDocumentation.html) gerado com base nos dados da classe 'Hello'
- hello.cpp # Definições da classe 'Hello'
- hello.h   # Declarações da classe 'Hello'
- teste.php # Código em PHP com exemplificações do uso do código gerado ao final do processo de conversão

Classes:
--------

- Hello

Convertendo sua classe C++ para PHP:
------------------------------------

Com base nos arquivos deste diretório, você realizará os seguintes comandos:

```
# Gerar wraper com base no arquivo de interface
swig -php -c++ hello.i

# Gerar arquivo objeto da classe CPP que será migrada para o PHP
g++ -fpic -c hello.cpp

# Gerar arquivo objeto da classe gerada pela interface embutindo as dependências do PHP
g++ `php-config --includes` -fpic -c hello_wrap.cpp

# Gerar extensão para o servidor PHP com todas as dependências do PHP, da classe de interface, objetos e métodos
g++ -shared *.o -o MyModule.so

# Copia o arquivo da extensão para o diretório de extensões do PHP
sudo cp hello.so `php-config --extension-dir`
```

Após esses comandos é necessário incluir o módulo novo ao 'php.ini'. Insira a seguinte linha o 'php.ini' do seu Apache:

```
extension=MyModule.so
```

Testes:
-------

Para verificar se sua nova extensão está funcionando acesse o arquivo 'teste.php' alocado no diretório público do seu Apache.

Referências:
------------

- http://max.berger.name/teaching/s06/ch11.jsp
- http://www.ibm.com/developerworks/opensource/library/os-php-swig/
- http://www.swig.org/Doc2.0/SWIGDocumentation.html#Php
- http://devzone.zend.com/1435/wrapping-c-classes-in-a-php-extension/