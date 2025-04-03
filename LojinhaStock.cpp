#include <iostream>
using namespace std;

void compra(int opc, float &cred,int stockArray[]) {
    char decisao;
    float precos[] = {0.0, 1.50, 1.00, 0.50, 1.25, 3.00, 3.50};
    int produtos;

    if (opc < 1 || opc > 6) {
        cout << "Opcao Invalida! Escolhe um numero de 1 a 6 só.\n";
        return;
    }

    cout << "\nEscolheste ";
    switch (opc) {
            case 1: cout << "o Paozinho"; 
            cout <<" Temos " << stockArray[opc] << " unidades restantes do mesmo/a." << endl;          
        break;
            case 2: cout << "o Leite"; 
            cout <<" Temos " << stockArray[opc] << " unidades restantes do mesmo/a." << endl;
        break;
            case 3: cout << "a Agua";
            cout <<" Temos " << stockArray[opc] << " unidades restantes do mesmo/a." << endl;
         break;
            case 4: cout << "a Manteiga"; 
            cout <<" Temos " << stockArray[opc] << " unidades restantes do mesmo/a." << endl;
        break;
            case 5: cout << "a Gelatina"; 
            cout <<" Temos " << stockArray[opc] << " unidades restantes do mesmo/a." << endl;
        break;
            case 6: cout << "os Crepes"; 
            cout <<" Temos " << stockArray[opc] << " unidades restantes do mesmo/a." << endl;
        break;


    }
    cout << "\nQuantas unidades queres comprar? " << endl;
    cin >> produtos;
    for(int i = 0; i < produtos; i++){
        if(stockArray[opc] == 0){
            cout << " Acabou o Stock " << endl;
            break;
        }
        if(produtos < 0){
            cout << "Escolhe um numero de unidades superior a 0." << endl;
            cout << "Por favor, escolhe um numero de unidades superior a 0." << endl;
            break;
        }
        
        if(produtos > stockArray[opc]){
            cout << "Temos apenas " << stockArray[opc] << " unidades do produto que pediste." << endl;
            cout << "Por favor, escolhe um numero de unidades inferior ou igual a " << stockArray[opc] << endl;
            break;
            
        }

    }
    cout << "\nPor $" << precos[opc]*produtos << ". Tens a certeza? (s/n): ";
    cin >> decisao;

    if (decisao == 's' || decisao == 'S') {

        if (cred >= precos[opc]) {
            if(stockArray[opc] > 0){
            cred -= precos[opc] * produtos;;
            stockArray[opc] -= produtos;
            cout << "\nCompra realizada com sucesso! Saldo restante: $" << cred << endl;
            cout << "\n" << stockArray[opc] << " restantes " << endl;
            if(stockArray[opc] == 0){
                cout << " Acabou o Stock " << endl;
                
            }
           }

        } else {
            cout << "Saldo insuficiente! Tens apenas $" << cred << endl;
        }
    } else {
        cout << "Compra cancelada.\n";
    }


    cout << "\nPressiona Enter se queres fazer Outra compra.";
    cin.ignore();
    cin.get();


    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    int opc;
    float cred = 1000.00;
    int stockArray[7] = {0, 3, 5, 10, 4, 20, 10};
   
   
    while (true) {
        cout << "-------------------------------------------------" << endl;
        cout << "|         Bem-vindo a Lojinha do Blud!          |" << endl;
        cout << "|        Aqui nos vendemos so o basico!         |" << endl;
        cout << "| 1 - Pao        ($1.50)                        |" << endl;
        cout << "| 2 - Leite      ($1.00)                        |" << endl;
        cout << "| 3 - Agua       ($0.50)                        |" << endl;
        cout << "| 4 - Manteiga   ($1.25)                        |" << endl;
        cout << "| 5 - Gelatina   ($3.00)                        |" << endl;
        cout << "| 6 - Crepes     ($3.50)                        |" << endl;
        cout << "| Escolha uma das opcoes pelo numero acima:     |" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Saldo Atual: $" << cred << endl;
        cout << "Digite 0 para sair da loja. " << endl;

        cin >> opc;

        if (opc == 0) {
            cout << "Obrigado por visitar a lojinha! Volte sempre!\n";
            break;
        }

        compra(opc, cred, stockArray);
    }

    return 0;
}
