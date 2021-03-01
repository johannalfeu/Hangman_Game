#include <iostream> // Biblioteca que define o espa�o de nomes;
#include <string> // Biblioteca que permite o uso de cadeia de caracteres;
#include <cstdlib> // Biblioteca que permite o sorteio das palavras aleat�rias;
#include <ctime> // Biblioteca que permite o sorteio das palavras aleat�rias;
#include <stdio.h> // Biblioteca que permite o uso do printf;
#include <conio.h> // Biblioteca que permite o uso do setlocale;
#include <locale.h> // Biblioteca que permite o uso do setlocale;
#include <ctype.h> // Biblioteca que permite o uso do tolower;
#include <vector>
#include <fstream>
// Andr� Prestes, Ismael Souto, Jo�o Pedro Loro Batista, Jo�o Pedro Servan, Johann Goulart, Jos� Natan da Silva;

using namespace std;

string CarregarPalavra(string path){
    int lineCount = 0;
    string Palavra;
    vector<string> v;
    ifstream reader(path.c_str());
    if (reader.is_open())
    {
        while (std::getline(reader, Palavra))
            v.push_back(Palavra);
 
        int randomLine = rand() % v.size();
 
        Palavra = v.at(randomLine);
        reader.close();
    }
    return Palavra;
}

int main(void){
	int jogar_novamente;
	do{
		system("color 0C");
		srand(time(0));
	    string PalavraSecreta;
	    PalavraSecreta = CarregarPalavra("forca.txt");
		setlocale(LC_ALL, "Portuguese");	
		char jogador [8] = "Jogador";
		char palavra[12];
		char letra;
		int CHANCES = 6;
		int palavra_sorteada, i;
		int quantidate_letras, erros, acertos;
		bool letra_correta, vencedor;
		quantidate_letras = PalavraSecreta.length();
		erros = 0;
		acertos = 0;
		letra_correta;
		vencedor = false;
		// inicia palavra descoberta como uma lista de "-"
		string descoberto = string(quantidate_letras, '-');
		
		while(erros <= CHANCES && acertos <= quantidate_letras){
	  		letra_correta = false;
			system ("cls");
	
	  		cout << "                                         J O G O   D A   F O R C A" << endl;
	  		cout << "\n";
	  		cout << "Bem vindo, Jogador! Esta vers�o s� est� dispon�vel para um participante por vez. Boa sorte!" << endl;
	  		cout << "\n";
			cout << "POR FAVOR DIGITE SEM ACENTO!!" << endl;
			cout << "\n";
	  		cout << "Jogador, insira seu palpite:" << endl;
	  		cout << "Voc� possui:" << ' ' << CHANCES - erros << ' ' << "chances." << endl;
	  		cout << "Voc� acertou:" << ' ' << acertos << ' ' << "letras" << endl;
	
	  	switch (erros){
		case 0:
         	cout<< ' '      <<endl;
         	cout<< ' '      <<endl;
            cout<<"  _____ "<<endl;
            cout<<" |      "<<endl;
            cout<<" |      "<<endl;
            cout<<" |      "<<endl;
            cout<<" |      "<<endl;
            break;
        case 1:
         	cout<< ' '      <<endl;
         	cout<< ' '      <<endl;
            cout<<"  _____ "<<endl;
            cout<<" |    O "<<endl;
            cout<<" |      "<<endl;
            cout<<" |      "<<endl;
            cout<<" |      "<<endl;
            break;
        case 2:
         	cout<< ' '      <<endl;
         	cout<< ' '      <<endl;
            cout<<"  _____ "<<endl;
            cout<<" |    O "<<endl;
            cout<<" |    | "<<endl;
            cout<<" |      "<<endl;
            cout<<" |      "<<endl;
            break;
        case 3:
         	cout<< ' '      <<endl;
         	cout<< ' '      <<endl;
            cout<<"  _____ "<<endl;
            cout<<" |    O "<<endl;
            cout<<" |   /| "<<endl;
            cout<<" |      "<<endl;
            cout<<" |      "<<endl;
            break;
        case 4:
         	cout<< ' '       <<endl;
         	cout<< ' '       <<endl;
            cout<<"  _____  "<<endl;
            cout<<" |    O  "<<endl;
            cout<<" |   /|\\"<<endl;
            cout<<" |       "<<endl;
            cout<<" |       "<<endl;
            break;
        case 5:
         	cout<< ' '       <<endl;
         	cout<< ' '       <<endl;
            cout<<"  _____  "<<endl;
            cout<<" |    O  "<<endl;
            cout<<" |   /|\\"<<endl;
            cout<<" |   /   "<<endl;
            cout<<" |       "<<endl;
            break;
        case 6:
         	cout<< ' '       <<endl;
         	cout<< ' '       <<endl;
            cout<<"  _____  "<<endl;
            cout<<" |    O  "<<endl;
            cout<<" |   /|\\"<<endl;
            cout<<" |   / \\"<<endl;
            cout<<" |       "<<endl;
            cout<< ' '       <<endl;
            break;
	  	}	
	
			cout << descoberto << endl;
	  		// verifica vitoria ou derrota
	  		if (acertos >= quantidate_letras){
				vencedor = true;
				break;
		  	}
		  	else if(erros >= CHANCES){
				break;
		 	}
		
		  	// ler caractere
		  	letra = getchar();
		
		  	// verifica se � um caractere v�lido, se n�o, pega o pr�ximo chute
		  	if(letra == '\n'){
				continue;
			}
				  	
			// verifica se � uma letra correta
			for(i = 0; i < PalavraSecreta.length(); i++){
				if(PalavraSecreta[i] == tolower(letra)){
			  		if(descoberto[i] != letra){
						descoberto[i] = letra;
						acertos++;
			  		}		
			 		letra_correta = true;
				}
		  	}
		  	if(!letra_correta){
				erros++;
			}
		}
	
		if(vencedor){
	  		cout << "PARAB�NS!!! Voc� ganhou! \n";
	  	}
		else{
	  		cout << "N�o foi dessa vez.\nPalavra correta: " << PalavraSecreta << "\n\n" << endl;
		}
		cout << "Deseja jogar novamente? Se sim, digite 1, se n�o, digite 2: ";
		cin >> jogar_novamente;

 	}while(jogar_novamente == 1);
	return 0;
}
