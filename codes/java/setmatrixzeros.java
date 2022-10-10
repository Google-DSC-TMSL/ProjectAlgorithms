public class setmatrixzeros {
    public static void setZeroes(int[][] matrix) {
        int[][] copy = new int[matrix.length][matrix[0].length];
        int i, j;
        for (i = 0; i < copy.length; i++) {
            for (j = 0; j < copy[0].length; j++) {
                copy[i][j] = matrix[i][j];
            }
        }
        for (i = 0; i < matrix.length; i++) {
            for (j = 0; j < matrix[i].length; j++) {
                if(copy[i][j]==0){
                    zerofi(matrix, i, j);
                }
            }
        }
    }
    public static void zerofi(int[][] arr, int row, int col){
        int i;
        for (i = 0; i < arr.length; i++) {
            arr[i][col] = 0;
        }
        for (i = 0; i < arr[0].length; i++) {
            arr[row][i] = 0;
        }
        
    }
    public static void main(String[] args) {
        int[][] arr = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
        // int[][] arr = {{1, 2, 3, 4}, {5, 0, 7, 8}, {9, 10, 11, 12}};
        setZeroes(arr);
        for(int i =0; i<arr.length; i++){
            for (int j = 0; j < arr[0].length; j++) {
                System.out.print(arr[i][j]+ " ");
            }
            System.out.println();
        }
    }
}