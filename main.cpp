#include <iostream>
#include <regex>
#include <string>

using namespace std;

struct Data {
    int dia;
    int mes;
    int ano;

    void setData(string data) {
        regex data_regex(R"(\d{1,2}/\d{1,2}/\d{4})"); // Expressão regular para validar datas no formato "DD/MM/AAAA"
        smatch match;

        if (regex_match(data, match, data_regex)) {
            sscanf(data.c_str(), "%d/%d/%d", &dia, &mes, &ano);
        } else {
            cout << "Formato de data inválido. Por favor, use o formato DD/MM/AAAA." << endl;
        }
    }

    string getData() {
        return to_string(dia) + "/" + to_string(mes) + "/" + to_string(ano);
    }
};

int main() {
    Data minhaData;
    string data;

    cout << "Digite uma data no formato DD/MM/AAAA: ";
    cin >> data;

    minhaData.setData(data); // Exemplo de data no formato DD/MM/AAAA

    cout << "Data: " << minhaData.getData() << endl;

    return 0;
}
