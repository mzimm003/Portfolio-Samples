/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.awt.*;
import javax.swing.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.logging.Level;
import java.util.logging.Logger;
//import javax.swing.Timer;

/**
 *
 * @author Mark
 */
public class gameBoard extends javax.swing.JFrame {
    /**
     * Creates new form gameBoard
     */
    public gameBoard(int height, int width) {
        rows = height;
        cols = width;
        initComponents(rows, cols);
    }
    
    private void initComponents(int height, int width){
        int buttonSize = 10;
        grid = new gridCell[height][width];
        livePixels = new ArrayList<Pixel>();
        runButton = new javax.swing.JButton();
        resetButton = new javax.swing.JButton();
        preset1Button = new javax.swing.JButton();
        preset2Button = new javax.swing.JButton();
        preset3Button = new javax.swing.JButton();
        preset4Button = new javax.swing.JButton();
        welcomeLabel = new javax.swing.JLabel();
        
        for(int pixelRow = 0; pixelRow < height; pixelRow++){
            for(int pixel = 0; pixel < width; pixel++){
                grid[pixelRow][pixel] = new gridCell(pixelRow,pixel);
                grid[pixelRow][pixel].setBackground(new java.awt.Color(255, 255, 255));
                grid[pixelRow][pixel].addActionListener(new java.awt.event.ActionListener() {
                    public void actionPerformed(java.awt.event.ActionEvent evt) {
                        pixelActionPerformed(evt);
                    }
                });
            }
        }
        
        running = new Timer(0, new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {               
                runningActionPerformed();
            }
        });
        
        runButton.setText("Give life!");
        runButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {                
                runButtonActionPerformed(evt);
                running.start();
            }
        });
        
        resetButton.setText("Reset");
        resetButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {                
                running.stop();
                resetButtonActionPerformed(evt);
            }
        });
        
        preset1Button.setText("Blinkers");
        preset1Button.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {                
                preset1ButtonActionPerformed();
            }
        });
        
        preset2Button.setText("Pulsar");
        preset2Button.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {                
                preset2ButtonActionPerformed();
            }
        });
        
        preset3Button.setText("Glider");
        preset3Button.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {                
                preset3ButtonActionPerformed();
            }
        });
        
        preset4Button.setText("Spaceship");
        preset4Button.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {                
                preset4ButtonActionPerformed();
            }
        });
        
        welcomeLabel.setText("<html>Welcome to Conway's Game of Life!<br>"
                + "Fill in the grid below however you like, give life, and enjoy the show.<br>"
                + "If you've never played before, filling in closer together will provide more exciting results.<br>"
                + "Or, try a preset:</html>");
        
        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        
        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        
        
        //Place elements in frame
        javax.swing.GroupLayout.ParallelGroup pixelGridHorizontalGroup = layout.createParallelGroup(javax.swing.GroupLayout.Alignment.CENTER);
        
        for(int pixelRow = 0; pixelRow < height; pixelRow++){
            javax.swing.GroupLayout.SequentialGroup currentGroup = layout.createSequentialGroup();
            for(int pixel = 0; pixel < width; pixel++){
                if(pixel == (width - 1)){
                    currentGroup.addComponent(grid[pixelRow][pixel], javax.swing.GroupLayout.PREFERRED_SIZE, buttonSize, javax.swing.GroupLayout.PREFERRED_SIZE);
                }
                else{
                    currentGroup.addComponent(grid[pixelRow][pixel], javax.swing.GroupLayout.PREFERRED_SIZE, buttonSize, javax.swing.GroupLayout.PREFERRED_SIZE);
                                //.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED);
                }
            }
            pixelGridHorizontalGroup.addGroup(currentGroup);
        }
       
        pixelGridHorizontalGroup.addGroup(layout.createSequentialGroup()
                .addComponent(runButton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(resetButton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE));
        
        pixelGridHorizontalGroup.addGroup(layout.createSequentialGroup()
                .addComponent(preset1Button, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(preset2Button, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(preset3Button, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(preset4Button, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE));
        
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addContainerGap()
                        .addGroup(pixelGridHorizontalGroup))                            
                    .addGroup(layout.createSequentialGroup()
                        .addGap(10, 10, 10)
                        .addComponent(welcomeLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE)))
                .addContainerGap())
        );
        
        
        javax.swing.GroupLayout.SequentialGroup sequentialVerticalGroup = layout.createSequentialGroup();
        sequentialVerticalGroup.addContainerGap()
                                .addComponent(welcomeLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 70, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(5,5,5)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                    .addComponent(preset1Button)
                                    .addComponent(preset2Button)
                                    .addComponent(preset3Button)
                                    .addComponent(preset4Button))
                               .addGap(0,0,0);
        
        for(int pixelRow = 0; pixelRow < height; pixelRow++){
            javax.swing.GroupLayout.ParallelGroup currentVerticalGroup = layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE);
            for(int pixel = 0; pixel < width; pixel++){
                currentVerticalGroup.addComponent(grid[pixelRow][pixel], javax.swing.GroupLayout.PREFERRED_SIZE, buttonSize, javax.swing.GroupLayout.PREFERRED_SIZE);                
            }
            sequentialVerticalGroup.addGroup(currentVerticalGroup);
            //sequentialVerticalGroup.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED);
        }
        
        sequentialVerticalGroup.addGap(6, 6, 6)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                    .addComponent(runButton)
                                    .addComponent(resetButton))
                                .addGap(6, 6, 6);
        
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(sequentialVerticalGroup)
        );

        pack();
    }
    
    private void runningActionPerformed(){
        //Conway's Step 1: Any live cell with two or three live neighbours survives (& Step 3, everyone else dies)
        for(Iterator<Pixel> livePixel = livePixels.iterator();livePixel.hasNext();){
            int neighborCount = countNeighbors(livePixel.next());
            if(!(neighborCount == 2 || neighborCount == 3)){
                livePixel.remove();
            }
        }
        //Conway's Step 2: Any dead cell with three live neighbours becomes a live cell
        for(int i = 0; i < this.rows; i++){
            for(int j = 0; j < this.cols; j++){
                if(!grid[i][j].isSelected()){
                    int neighborCount = countNeighbors(grid[i][j]);
                    if(neighborCount == 3){
                        livePixels.add(new Pixel(grid[i][j].getRow(),grid[i][j].getCol(), this));
                    }
                }
            }
        }

        //Display resutls
        for(int i = 0; i < this.rows; i++){
            for(int j = 0; j < this.cols; j++){
                if(grid[i][j].isSelected()){
                    grid[i][j].setSelected(false);
                    grid[i][j].setBackground(new java.awt.Color(255, 255, 255));
                }
            }
        }
        for(Pixel livePixel : livePixels){
            grid[livePixel.getRow()][livePixel.getCol()].setSelected(true);
            grid[livePixel.getRow()][livePixel.getCol()].setBackground(new java.awt.Color(0, 0, 0));
        }
        
        try {
            Thread.sleep(150);
        } catch (InterruptedException ex) {
            Logger.getLogger(gameBoard.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    private void runButtonActionPerformed(java.awt.event.ActionEvent evt) {
        
        //Read 
        for(int i = 0; i < this.rows; i++){
            for(int j = 0; j < this.cols; j++){
                if(grid[i][j].isSelected()){
                    livePixels.add(new Pixel(grid[i][j].getRow(),grid[i][j].getCol(), this));
                }
            }
        }
        
    }
    
    private void resetButtonActionPerformed(java.awt.event.ActionEvent evt){
        for(int i = 0; i < this.rows; i++){
            for(int j = 0; j < this.cols; j++){
                if(grid[i][j].isSelected()){
                    grid[i][j].setSelected(false);
                    grid[i][j].setBackground(new java.awt.Color(255, 255, 255));
                }
            }
        }
        livePixels.clear();
    }
    
    private void preset1ButtonActionPerformed(){
        for(int i = 2; (i + 2) < rows; i += 5){
            for(int j = 2; (j + 2) < cols; j += 5){
                if((i + j) % 2 == 0){
                    grid[i - 1][j].setSelected(true);
                    grid[i - 1][j].setBackground(new java.awt.Color(0, 0, 0));
                    grid[i][j].setSelected(true);
                    grid[i][j].setBackground(new java.awt.Color(0, 0, 0));
                    grid[i + 1][j].setSelected(true);
                    grid[i + 1][j].setBackground(new java.awt.Color(0, 0, 0));
                }
                else{
                    grid[i][j - 1].setSelected(true);
                    grid[i][j - 1].setBackground(new java.awt.Color(0, 0, 0));
                    grid[i][j].setSelected(true);
                    grid[i][j].setBackground(new java.awt.Color(0, 0, 0));
                    grid[i][j + 1].setSelected(true);
                    grid[i][j + 1].setBackground(new java.awt.Color(0, 0, 0));                    
                }
            }
        }
    }
    
    private void preset2ButtonActionPerformed(){
        int midRow = rows / 2;
        int midCol = cols / 2;
        
        //Top border
        grid[midRow - 6][midCol - 4].setSelected(true);
        grid[midRow - 6][midCol - 4].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow - 6][midCol - 3].setSelected(true);
        grid[midRow - 6][midCol - 3].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow - 6][midCol - 2].setSelected(true);
        grid[midRow - 6][midCol - 2].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow - 6][midCol + 2].setSelected(true);
        grid[midRow - 6][midCol + 2].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow - 6][midCol + 3].setSelected(true);
        grid[midRow - 6][midCol + 3].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow - 6][midCol + 4].setSelected(true);
        grid[midRow - 6][midCol + 4].setBackground(new java.awt.Color(0, 0, 0));
        
        //Bottom border
        grid[midRow + 6][midCol - 4].setSelected(true);
        grid[midRow + 6][midCol - 4].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow + 6][midCol - 3].setSelected(true);
        grid[midRow + 6][midCol - 3].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow + 6][midCol - 2].setSelected(true);
        grid[midRow + 6][midCol - 2].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow + 6][midCol + 2].setSelected(true);
        grid[midRow + 6][midCol + 2].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow + 6][midCol + 3].setSelected(true);
        grid[midRow + 6][midCol + 3].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow + 6][midCol + 4].setSelected(true);
        grid[midRow + 6][midCol + 4].setBackground(new java.awt.Color(0, 0, 0));
        
        //Left border
        grid[midRow - 4][midCol - 6].setSelected(true);
        grid[midRow - 4][midCol - 6].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow - 3][midCol - 6].setSelected(true);
        grid[midRow - 3][midCol - 6].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow - 2][midCol - 6].setSelected(true);
        grid[midRow - 2][midCol - 6].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow + 2][midCol - 6].setSelected(true);
        grid[midRow + 2][midCol - 6].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow + 3][midCol - 6].setSelected(true);
        grid[midRow + 3][midCol - 6].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow + 4][midCol - 6].setSelected(true);
        grid[midRow + 4][midCol - 6].setBackground(new java.awt.Color(0, 0, 0));
        
        //Right border
        grid[midRow - 4][midCol + 6].setSelected(true);
        grid[midRow - 4][midCol + 6].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow - 3][midCol + 6].setSelected(true);
        grid[midRow - 3][midCol + 6].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow - 2][midCol + 6].setSelected(true);
        grid[midRow - 2][midCol + 6].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow + 2][midCol + 6].setSelected(true);
        grid[midRow + 2][midCol + 6].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow + 3][midCol + 6].setSelected(true);
        grid[midRow + 3][midCol + 6].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow + 4][midCol + 6].setSelected(true);
        grid[midRow + 4][midCol + 6].setBackground(new java.awt.Color(0, 0, 0));
        
        //Top of cross
        grid[midRow + 4][midCol + 1].setSelected(true);
        grid[midRow + 4][midCol + 1].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow + 3][midCol + 1].setSelected(true);
        grid[midRow + 3][midCol + 1].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow + 2][midCol + 1].setSelected(true);
        grid[midRow + 2][midCol + 1].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow + 2][midCol - 1].setSelected(true);
        grid[midRow + 2][midCol - 1].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow + 3][midCol - 1].setSelected(true);
        grid[midRow + 3][midCol - 1].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow + 4][midCol - 1].setSelected(true);
        grid[midRow + 4][midCol - 1].setBackground(new java.awt.Color(0, 0, 0));
        
        //Bottom of cross
        grid[midRow - 4][midCol + 1].setSelected(true);
        grid[midRow - 4][midCol + 1].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow - 3][midCol + 1].setSelected(true);
        grid[midRow - 3][midCol + 1].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow - 2][midCol + 1].setSelected(true);
        grid[midRow - 2][midCol + 1].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow - 2][midCol - 1].setSelected(true);
        grid[midRow - 2][midCol - 1].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow - 3][midCol - 1].setSelected(true);
        grid[midRow - 3][midCol - 1].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow - 4][midCol - 1].setSelected(true);
        grid[midRow - 4][midCol - 1].setBackground(new java.awt.Color(0, 0, 0));
        
        //Left of cross
        grid[midRow + 1][midCol - 4].setSelected(true);
        grid[midRow + 1][midCol - 4].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow + 1][midCol - 3].setSelected(true);
        grid[midRow + 1][midCol - 3].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow + 1][midCol - 2].setSelected(true);
        grid[midRow + 1][midCol - 2].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow - 1][midCol - 2].setSelected(true);
        grid[midRow - 1][midCol - 2].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow - 1][midCol - 3].setSelected(true);
        grid[midRow - 1][midCol - 3].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow - 1][midCol - 4].setSelected(true);
        grid[midRow - 1][midCol - 4].setBackground(new java.awt.Color(0, 0, 0));
        
        //Right of cross
        grid[midRow + 1][midCol + 4].setSelected(true);
        grid[midRow + 1][midCol + 4].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow + 1][midCol + 3].setSelected(true);
        grid[midRow + 1][midCol + 3].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow + 1][midCol + 2].setSelected(true);
        grid[midRow + 1][midCol + 2].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow - 1][midCol + 2].setSelected(true);
        grid[midRow - 1][midCol + 2].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow - 1][midCol + 3].setSelected(true);
        grid[midRow - 1][midCol + 3].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow - 1][midCol + 4].setSelected(true);
        grid[midRow - 1][midCol + 4].setBackground(new java.awt.Color(0, 0, 0));
    }
    
    private void preset3ButtonActionPerformed(){
        grid[0][2].setSelected(true);
        grid[0][2].setBackground(new java.awt.Color(0, 0, 0));
        grid[1][2].setSelected(true);
        grid[1][2].setBackground(new java.awt.Color(0, 0, 0));
        grid[2][2].setSelected(true);
        grid[2][2].setBackground(new java.awt.Color(0, 0, 0));
        grid[2][1].setSelected(true);
        grid[2][1].setBackground(new java.awt.Color(0, 0, 0));
        grid[1][0].setSelected(true);
        grid[1][0].setBackground(new java.awt.Color(0, 0, 0));
    }
    
    private void preset4ButtonActionPerformed(){
        int midRow = rows / 2;
        
        grid[midRow - 1][4].setSelected(true);
        grid[midRow - 1][4].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow - 1][5].setSelected(true);
        grid[midRow - 1][5].setBackground(new java.awt.Color(0, 0, 0));
        
        grid[midRow][0].setSelected(true);
        grid[midRow][0].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow][1].setSelected(true);
        grid[midRow][1].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow][2].setSelected(true);
        grid[midRow][2].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow][3].setSelected(true);
        grid[midRow][3].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow][5].setSelected(true);
        grid[midRow][5].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow][6].setSelected(true);
        grid[midRow][6].setBackground(new java.awt.Color(0, 0, 0));
        
        grid[midRow + 1][0].setSelected(true);
        grid[midRow + 1][0].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow + 1][1].setSelected(true);
        grid[midRow + 1][1].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow + 1][2].setSelected(true);
        grid[midRow + 1][2].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow + 1][3].setSelected(true);
        grid[midRow + 1][3].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow + 1][4].setSelected(true);
        grid[midRow + 1][4].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow + 1][5].setSelected(true);
        grid[midRow + 1][5].setBackground(new java.awt.Color(0, 0, 0));
        
        grid[midRow + 2][1].setSelected(true);
        grid[midRow + 2][1].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow + 2][2].setSelected(true);
        grid[midRow + 2][2].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow + 2][3].setSelected(true);
        grid[midRow + 2][3].setBackground(new java.awt.Color(0, 0, 0));
        grid[midRow + 2][4].setSelected(true);
        grid[midRow + 2][4].setBackground(new java.awt.Color(0, 0, 0));
    }

    private void pixelActionPerformed(java.awt.event.ActionEvent evt) {                                       
        //set grid cells 
        gridCell pixel = (gridCell)evt.getSource();
        if(pixel.isSelected()){
            pixel.setBackground(new java.awt.Color(0, 0, 0));
        }
        else{
            pixel.setBackground(new java.awt.Color(255, 255, 255));
        }        
    }
    
    public int countNeighbors(Pixel considerPixel){
        int livePixelCount = 0;
        for(int i = 0; i < 8; i++){
            int lookUpDown = (i / 3 + 2) % 3 - 1; //determines vertical search direction (i={0-2} => 1(row below), i={3-5} => -1(row above), i={6-7} => 0(current row))
            int lookLeftRight = (i + 2) % 3 - 1; //determines horizontal search direction (i={0,3,6} => 1(right col), i={1,4,7} => -1(left col), i={2,5} => 0(current col))
            
            if(considerPixel.getRow() + lookUpDown < 0 ||
               considerPixel.getRow() + lookUpDown >= this.rows ||
               considerPixel.getCol() + lookLeftRight < 0 ||
               considerPixel.getCol() + lookLeftRight >= this.cols){
                //Do nothing, checking out of grid bounds
            }
            else if(grid[considerPixel.getRow() + lookUpDown][considerPixel.getCol() + lookLeftRight].isSelected()){
                livePixelCount++;
            }
        }
        return livePixelCount;
    }
    
    public int countNeighbors(gridCell considerPixel){
        int livePixelCount = 0;
        for(int i = 0; i < 8; i++){
            int lookUpDown = (i / 3 + 2) % 3 - 1; //determines vertical search direction (i={0-2} => 1(row below), i={3-5} => -1(row above), i={6-7} => 0(current row))
            int lookLeftRight = (i + 2) % 3 - 1; //determines horizontal search direction (i={0,3,6} => 1(right col), i={1,4,7} => -1(left col), i={2,5} => 0(current col))
            
            if(considerPixel.getRow() + lookUpDown < 0 ||
               considerPixel.getRow() + lookUpDown >= this.rows ||
               considerPixel.getCol() + lookLeftRight < 0 ||
               considerPixel.getCol() + lookLeftRight >= this.cols){
                //Do nothing, checking out of grid bounds
            }
            else if(grid[considerPixel.getRow() + lookUpDown][considerPixel.getCol() + lookLeftRight].isSelected()){
                livePixelCount++;
            }
        }
        return livePixelCount;
    }
    
    public int getRows(){
        return rows;
    }
    
    public int getCols(){
        return cols;
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(gameBoard.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(gameBoard.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(gameBoard.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(gameBoard.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        
        /* Create and display the form */
        final int boardHeight = 30;
        final int boardWidth = 50;
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new gameBoard(boardHeight, boardWidth).setVisible(true);
            }
        });
        
        
    }
    
    private gridCell[][] grid;
    private ArrayList<Pixel> livePixels;
    private int rows;
    private int cols;
    private javax.swing.JButton runButton;
    private javax.swing.JButton resetButton;
    private javax.swing.JButton preset1Button;
    private javax.swing.JButton preset2Button;
    private javax.swing.JButton preset3Button;
    private javax.swing.JButton preset4Button;
    private javax.swing.JLabel welcomeLabel;
    private Timer running;
}
