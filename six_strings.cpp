#include<bits/stdc++.h>
using namespace std;

#define MAX 100000
char sequencia1[MAX];
char sequencia2[MAX];
int tabela[2][MAX + 1];// tabela dinâmica
int custo_inserir_deletar = 1; 
int custo_trocar = 1;

int hammingDist(string str1, string str2)
{
	int i = 0, count = 0;
	while (str1[i] != '\0') {
		if (str1[i] != str2[i])
			count++;
		i++;
	}
	return count;
}

int main() {
  int closest_distance, closest_distance_index, current_distance;

  string main_string;
  string compare_string;
  int number_of_comparisions;

  cin >> main_string;

  // for (int j = 0; j < main_string.length(); j++){
  //   sequencia1[j] = main_string[j];
  // }

  cin >> number_of_comparisions;
  closest_distance = number_of_comparisions +1;

  for (int i = 0; i < number_of_comparisions; i++){

      cin >> compare_string;

      // for (int j = 0; j < compare_string.length(); j++)
      //   sequencia2[j] = compare_string[j];

      current_distance = hammingDist(main_string, compare_string);

      if(current_distance < closest_distance) {
        closest_distance = current_distance;
        closest_distance_index = i+1;
      }
    
  }

  if(number_of_comparisions > closest_distance) {
    cout << closest_distance_index << endl;
    cout << closest_distance << endl;
  } else {
    cout << -1<< endl;
  }
  
  return 0;
}