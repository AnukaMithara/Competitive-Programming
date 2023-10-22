#include <iostream>
#include <list>

int main() {
    int N;
    std::cin >> N;

    // Create a list of 2D arrays
    std::list<int[50][50]> images;

    for (int i = 0; i < N; i++) {
        std::cin.ignore(); // To ignore the empty line

        int image[50][50];
        for (int j = 0; j < 50; j++) {
            for (int k = 0; k < 50; k++) {
                char pixel;
                std::cin >> pixel;
                image[j][k] = (pixel == '1') ? 1 : 0;
            }
        }

        // Add the current image to the list
        images.push_back(image);
    }

    // Example usage: print out each image in the list
    for (const auto &image : images) {
        for (int j = 0; j < 50; j++) {
            for (int k = 0; k < 50; k++) {
                std::cout << image[j][k] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
