#include <iostream>
#include <cstdarg> 
#include <vector>

void test_function(int num, ...) {
    va_list args;
    va_start(args, num); 

    for (int i = 0; i < num; i++) {
        va_arg(args, int); 
    }

    va_end(args); 
}

int main() {
    std::vector<int> memory_hog; 
    for (long long int i = 0; i <= 2570000000; i +=10000000 ) {
        std::cout << "Tentative avec " << i << " parametres." << std::endl;
        
        try {
            memory_hog.resize(i, 1); 
            test_function(i, 1, 2, 3, 4, 5);
            std::cout << "Test reussi avec " << i << " parametres." << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Erreur detectee avec " << i << " parametres : " << e.what() << std::endl;
            break;
        } catch (...) {
            std::cerr << "Erreur inconnue avec " << i << " parametres." << std::endl;
            break;
        }
    }

    return 0;
}
