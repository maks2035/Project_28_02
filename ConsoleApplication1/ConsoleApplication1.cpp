#include <iostream>
#include <omp.h>


int main() {
   setlocale(LC_ALL, "Russian");

#pragma omp parallel for
   for (int i = 0; i < 4; i++) {
#pragma omp critical
      std::cout << "Привет, мир" << std::endl;
   }


   int k = 5; 
   //std::cin >> k;
#pragma omp parallel for
   for (int i = 0; i < k; i++) {
   #pragma omp critical
         std::cout << "Нить " << i << ", всего нитей " << k << std::endl;
   }

   int rank;
//#pragma omp parallel num_threads(k) shared(rank)
#pragma omp parallel num_threads(k) private(rank)
   {
         rank = omp_get_thread_num(); 

#pragma omp critical
         printf("Я поток № %d.\n", rank);
   }

   return 0;
}