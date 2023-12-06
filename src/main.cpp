/*
TODO:
- Adicionar contatos
- Editar contatos
- Excluir contatos
- Buscar contatos
- Listar contatos
- Organizar contatos por diferentes categorias
- Armazenamento persistente
- Validação de entradas
- Interface gráfica
*/

#include <iostream>

using namespace std;

class Contato {
public:
    Contato(const string& nome, const string& numero)
        : nome(nome), numero(numero) {
        }

    void exibir_contato() {
        cout << nome << endl;
        cout << numero << endl;
    }

private:
    string nome;
    string numero;
    string email;
    string endereco;
};

int main() {
    Contato *contato = new Contato("Gabriel", "85996157285");

    contato->exibir_contato();

    delete contato;

    return 0;
}

