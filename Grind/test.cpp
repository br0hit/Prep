#include <iostream>
#include <vector>

int main()
{
    // Create a vector
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Remove the element at index 2 (the third element)
    vec.erase(vec.begin() + 2);

    // Print the vector after removal
    for (int num : vec)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
