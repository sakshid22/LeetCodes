//348
public class TicTacToe {
private int[][] rows;
private int[][] cols;
private int[]diag;
private int[]xdiag;
private int n;

//Structure

public TicTacToe(int n)
{
this.n =n;
rows = new int[2][n];
cols = new int[2][n];
diag = new int[2];
xdiag= new int[2];
}
public int move(int row, int col, int player)
{
int p=player ==1 ? 0:1;

rows[p][row]++;
cols[p][col]++;

    if(row==col)
    diag[p]++;

//X-Diagonal
    if(row + col == n-1)
    xdiag[p]++;

//Any of them equals to n, return 1
    if(rows[p][row] ==n || cols[p][col] ==n ||diag[p] ==n || xdaig[p] == n)
    return p+1;
}
return 0;


}
