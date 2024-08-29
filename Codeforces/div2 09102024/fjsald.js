// Function to calculate the weights for the bouncing diagonals
const getWeights = matrix => {
  let weights = [];
  let size = matrix.length - 1;

  for (let i = 0; i <= size; i++) {
    let key = matrix[i][0];
    let weight = 0;

    for (let j = 0; j <= size; j++) {
      if (i === 0) {
        // For the first row, only one diagonal (down-right)
        weight += matrix[j][j];
      } else if (i === size) {
        // For the last row, only one diagonal (up-right)
        weight += matrix[size - j][j];
      } else {
        // For rows in between, two diagonals (up-right and down-right)
        let diagonalUp = Math.abs(j - i);
        let diagonalDown = size - (Math.abs(size - (i + j)) % size);
        weight += matrix[diagonalUp][j];
        weight += matrix[diagonalDown][j];
      }
    }

    weights.push([key, weight]);
  }

  return weights;
};

// Function to sort the weights first by weight, then by value in case of ties
const sort = weights => {
  let results = [...weights];
  results.sort((first, second) => {
    // Compare Weights
    if (first[1] > second[1]) return 1;
    if (first[1] < second[1]) return -1;

    // Compare Keys (matrix values) in case of tie
    if (first[0] < second[0]) return -1;
    if (first[0] > second[0]) return 1;

    return 0;
  });

  return results.map(result => result[0]);
};

// Function to bring everything together
const bouncingMatrix = matrix => {
  let weights = getWeights(matrix);
  return sort(weights);
};

// Example usage
let matrix = [
  [1, 3, 2, 5],
  [3, 2, 5, 0],
  [9, 0, 1, 3],
  [6, 1, 0, 8]
];

let sortedColumn = bouncingMatrix(matrix);
console.log(sortedColumn); // Output should be [1, 9, 3, 6]
