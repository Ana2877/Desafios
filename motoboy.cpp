// C++ implementation to find the
// shortest path in a directed
// graph from source vertex to
// the destination vertex
#include<bits/stdc++.h>
using namespace std;

#define MAXN 10000
#define MAXP 10000
int valores[MAXN]; // vetor com os valores dos itens
int pesos[MAXN]; // vetor com os pesos dos itens
int quantidades[MAXN]; // vetor com as quantidades disponíveis dos itens
int n; // quantidade de itens
int tabela[2][MAXP + 1]; // tabela dinâmica (só duas linhas), inicializada com zeros

int mochila(int peso_mochila) {
  int atual = 0; // variável que indica a linha atual
  for (int item = n - 1; item >= 0; item--) {
    // troca a linha atual no início de cada iteração
    atual = 1 - atual;
    for (int peso = 0; peso <= peso_mochila; peso++) {
    // obter a melhor solução da linha anterior sem colocar o item
    int solucao = tabela[1 - atual][peso];
    // percorre a quantidade de itens que pode carregar do mesmo tipo
    for (int i = 1; i * pesos[item] <= peso && i <= quantidades[item]; i++) {
      // escolher a melhor solução
      if (solucao < i * valores[item] + tabela[1 - atual][peso - i * pesos[item]]) 
        solucao = i * valores[item] + tabela[1 - atual][peso - i * pesos[item]];
    }
    // colocar a solução encontrada na posição correspondente da tabela
    tabela[atual][peso] = solucao;
    }
  }
  // Retorna a solução equivalente na última linha calculada com o peso total
  return tabela[atual][peso_mochila];
}

int main() {
  int number_of_orders;
  int number_of_pizzas_roberto_can_deliver;
  int total_time, number_of_pizzas;

  cin >> number_of_orders;
    
  while(number_of_orders != 0) {
    n = 0;
    fill(valores, valores+MAXN, 0);
    fill(pesos, pesos+MAXN, 0);
    fill(quantidades, quantidades+MAXN, 0);
    memset(tabela,0,sizeof(tabela));
    
    cin >> number_of_pizzas_roberto_can_deliver;

    for(int i = 0; i < number_of_orders; i++) {
      cin >> total_time >> number_of_pizzas;
      
      valores[i] = total_time;
      pesos[i] = number_of_pizzas;
      quantidades[i] = 1;
      
      n += number_of_pizzas;
    }

    cout << mochila(number_of_pizzas_roberto_can_deliver) << " min." << endl;
    
    cin >> number_of_orders;
  }

  
  return 0;
}