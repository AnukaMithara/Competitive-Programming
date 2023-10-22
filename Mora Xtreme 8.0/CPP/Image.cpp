#include <iostream>
#include <array>
#include <vector>


void findMarginGradientAndYIntercept(std::array<std::array<int, 50>, 50> &image, float &m, float &c) {
    std::vector<int> x_values, y_values;

    for (int j = 0; j < 50; j++) {
        for (int k = 0; k < 50; k++) {
            if (j == 0 || j == 49 || k == 0 || k == 49) {
                if (image[j][k] == 1) {
                    x_values.push_back(k);
                    y_values.push_back(j);
                }
            }
        }
    }

    float avg_x = 0, avg_y = 0;
    for (int i = 0; i < x_values.size(); i++) {
        avg_x += x_values[i];
        avg_y += y_values[i];
    }
    avg_x /= x_values.size();
    avg_y /= y_values.size();

    float numerator = 0, denominator = 0;
    for (int i = 0; i < x_values.size(); i++) {
        numerator += (x_values[i] - avg_x) * (y_values[i] - avg_y);
        denominator += (x_values[i] - avg_x) * (x_values[i] - avg_x);
    }
    m = numerator / denominator;
    c = avg_y - m * avg_x;
}


int main() {
    int N;
    std::cin >> N;

    std::vector<std::array<std::array<int, 50>, 50>> images;

    for (int i = 0; i < N; i++) {
        std::array<std::array<int, 50>, 50> image;
        for (int j = 0; j < 50; j++) {
            for (int k = 0; k < 50; k++) {
                char pixel;
                std::cin >> pixel;
                image[j][k] = (pixel == '1') ? 1 : 0;
            }
        }
        images.push_back(image);
    }

    // Print out each image in the vector
    for (int i =0; i < N; i++) {
    float m, c;
    findMarginGradientAndYIntercept(images[i], m, c);
     std::cout << m << " " << c << std::endl;    
    }

    return 0;
}
