
#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;

		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista já possuir elementos
	// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	NO* aux = primeiro;
	if (primeiro == NULL) {
		cout << "Lista vazia!";
	}
	else {
		cout << "Elementos: \n";
		while (aux!= NULL) {
			cout << aux->valor <<endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	cout << "Insira\n";
	cin >> novo->valor;

	if (novo == NULL) {
		return;
	}
	novo->prox = NULL;
	if (primeiro == NULL) {
		primeiro = novo;
	}
	else {
		NO* aux = primeiro;
		while (aux->prox != NULL) {
			aux = aux->prox;
		}
		aux->prox = novo;
	}
}

void excluirElemento()
{
	NO* aux = primeiro;
	NO* anterior = NULL;
	

	
	int n = 0;
	cout << "Insira o valor que deseja excluir: ";
	cin >> n;
	NO* busca = posicaoElemento(n);
	
	if (primeiro == NULL) {
		cout << "Lista vazia!\n";
		return;
	}
	if (busca == NULL) {
		cout << "Numero nao existe na lista\n";
		return;
	}
	if (primeiro->valor == n) {
		primeiro = primeiro->prox;
		return;
	}
	while (aux->valor != n) {
		anterior = aux;
		aux = aux->prox;	
	}
	anterior->prox = aux->prox;
	free(aux);
}

void buscarElemento()
{
	int numero = 0;
	cout << "Insira\n";
	cin >> numero;

	NO* busca = posicaoElemento(numero);
	if (busca != NULL) {
		cout << "Encontrado\n";
	}
	else {
		cout << "Nao encontrado\n";
	}
}



// retorna um ponteiro para o elemento buscado
// ou NULL se o elemento não estiver na lista
NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (numero == aux->valor) {
			break;
		}
		aux = aux->prox;
	}
	return aux;

	
}