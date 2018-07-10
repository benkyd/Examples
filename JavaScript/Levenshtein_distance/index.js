/**
 * @param {string} a 
 * @param {string} b 
 */
module.exports.distance = function(a, b) {
    aL = a.length;
    bL = b.length;

    if (aL == 0) return aL;
    if (bL == 0) return bL;

    let matrix = [];

    for (let i = 0; i <= bL; i++) {
        matrix[i] = [i];
    }

    for (let i = 0; i <= aL; i++) {
        matrix[0][i] = i;
    }

    for (let i = 1; i <= bL; i++) {
        for (let j = 1; j <= aL; j++) {
            if (b.charAt(i-1) == a.charAt(j-1)) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                matrix[i][j] = Math.min(matrix[i-1][j-1] + 1,
                               Math.min(matrix[ i ][j-1] + 1,
                               matrix[i-1][j] + 1));
            }
        }
    }

    return matrix[bL][aL];
}
// we're doing the matrix implimentation https://en.wikipedia.org/wiki/Levenshtein_distance
