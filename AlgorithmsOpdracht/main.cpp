#include <iostream>

#include <vector>
#include <algorithm>
#include <numeric>

template<typename T>
void printVector(const std::vector<T>& vect) {
    std::cout << "| ";
    for (const T& elem : vect) {
        std::cout << elem << " | ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "---------" << std::endl;
    std::cout << " colours" << std::endl;
    std::cout << "---------" << std::endl;
    std::vector<std::string> colours{"red", "green", "white", "blue", "orange", "green", "orange", "black", "purple"};
    // gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
    // 1) de vector in 2 nieuwe vectoren te splitsen: 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na
    {
        // Copy original vector
        auto coloursCopy = colours;
        // Create two empty vectors for both sets of elements
        std::vector<std::string> beforePurple{};
        std::vector<std::string> afterPurple{};

        // Copy-partition the original vector into beforePurple and afterPurple based on the condition elem < "purple"
        std::partition_copy(colours.begin(), colours.end(), std::back_inserter(beforePurple),
                            std::back_inserter(afterPurple), [](const auto& elem) { return elem < "purple"; });

        // print vectors
        std::cout << "Elements before purple (alphabetically):" << std::endl;
        printVector(beforePurple);
        std::cout << "Elements alphabetically after purple:" << std::endl;
        printVector(afterPurple);
    }
    // 2) alle elementen UPPERCASE te maken.
    {
        auto coloursCopy = colours;
        std::for_each(coloursCopy.begin(), coloursCopy.end(), [](std::string& elem) {
            // Convert word to uppercase using stl transform
            std::transform(elem.begin(), elem.end(), elem.begin(), ::toupper);
        });

        std::cout << "Converted all elements to uppercase:" << std::endl;
        printVector(coloursCopy);
    }
    // 3) alle dubbele te verwijderen
    {
        // tutorial used: https://www.geeksforgeeks.org/stdunique-in-cpp/

        auto coloursCopy = colours;
        // First sort the vector
        std::sort(coloursCopy.begin(), coloursCopy.end());
        // Remove the doubles
        auto it = std::unique(coloursCopy.begin(), coloursCopy.end());
        // Resize to 'it'
        coloursCopy.resize(std::distance(coloursCopy.begin(), it));

        std::cout << "Removed all doubles:" << std::endl;
        printVector(coloursCopy);
    }

    std::cout << "---------" << std::endl;
    std::cout << " numbers" << std::endl;
    std::cout << "---------" << std::endl;

    std::vector<double> numbers{10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635};
    // gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
    // 1) alle negatieve elementen te verwijderen
    {
        // Copy the vector
        auto numbersCopy = numbers;
        // Remove the elements if they are <0, and store the iterator to after the last element
        auto it = std::remove_if(numbersCopy.begin(), numbersCopy.end(), [](const auto& elem) { return elem < 0; });
        // Resize the vector
        numbersCopy.resize(std::distance(numbersCopy.begin(), it));

        std::cout << "Removed all negative elements:" << std::endl;
        printVector(numbersCopy);
    }
    // 2) voor alle elementen te bepalen of ze even of oneven zijn
    {
        std::cout << std::endl;
        // It's a bit hard to check if a decimal number is even or odd so the only real solution to this exercise would
        // be to cast the numbers to an int.
        // The exercise also doesn't specify what to do with the check if it is odd or even so I'll just print it, I
        // guess?
        std::for_each(numbers.begin(), numbers.end(), [](auto& elem) {
            // Check if it is even or odd
            bool isEven = ((int) elem) % 2 == 0;
            // Print the result
            std::cout << elem << "(" << ((int) elem) << ")" << ": " << (isEven ? "even" : "odd") << std::endl;
        });
    }
    // 3) de som, het gemiddelde, en het product van alle getallen te berekenen
    {
        // Calculate the sum (using foreach but accumulate is also an option, but it's not in these headers)
        double sum = std::accumulate(numbers.begin(), numbers.end(), 0.0);

        // Calculate average
        double average = sum / numbers.size();

        // Calculate product by starting with elem 0, then looping over elems 1-size() and multiplying the first number
        // by each elem.
        double product = numbers[0];
        std::for_each(numbers.begin() + 1, numbers.end(), [&](auto elem) {
            product *= elem;
        });

        std::cout << std::endl;
        std::cout << "Sum: " << sum << std::endl;
        std::cout << "Average: " << average << std::endl;
        std::cout << "Product: " << product << std::endl;
    }
}