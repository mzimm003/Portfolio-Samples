/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Mark
 */
public class Pixel {

    Pixel(){
        row = 0;
        col = 0;
        grid = null;
    }
    
    Pixel(int row, int col, gameBoard grid){
        this.row = row;
        this.col = col;
        this.grid = grid;
    }
    
    public int getRow(){
        return row;
    }
    
    public int getCol(){
        return col;
    }
    
    private int row;
    private int col;
    private gameBoard grid;
}
