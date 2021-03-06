int countServers(int** grid, int gridSize, int* gridColSize){
    int t = 0, r = gridSize, c = *gridColSize, **g = grid;
    for (int i = 0 ; i < r ; i++)
        for (int j = 0, n = 0 ; j < c ; t += n, n = 0, j++) {
            for (int k = -1 ; ++k < c && !n && g[i][j] ; n = !n ? k != j && g[i][k] : 1);
            for (int k = -1 ; ++k < r && !n && g[i][j] ; n = !n ? k != i && g[k][j] : 1);
        }
    return t;
}
