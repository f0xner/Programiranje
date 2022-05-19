let board = [
    [5, 0, 0, 0, 7, 0, 0, 1, 0],
    [0, 0, 4, 0, 0, 6, 0, 0, 9],
    [7, 0, 0, 0, 0, 0, 0, 6, 0],
    [6, 0, 0, 9, 5, 0, 0, 0, 0],
    [0, 5, 2, 6, 4, 8, 0, 0, 0],
    [8, 0, 0, 3, 0, 0, 0, 0, 0],
    [2, 0, 5, 8, 0, 0, 0, 4, 0],
    [1, 0, 8, 0, 0, 0, 0, 0, 7],
    [0, 9, 0, 0, 0, 0, 2, 5, 0]
]
function get_valids(i,j){
    var valids = [];
    var add = true;
    var ib = Math.floor(i/3)*3;
    var jb = Math.floor(j/3)*3;
    for (let num = 1;num<10;num++){
        add = true;
        for (let x = 0;x<9;x++){
            if (board[x][j] == num || board[i][x] == num){
                add = false;
                break;
            }
        }
        for (let g = ib;g<ib+3;g++){
            for (let h = jb;h<jb+3;h++){
                if (board[g][h] == num){
                    add = false;
                    break;
                }
            }
        }
        if (add == true){
            valids.push(num);
        }
    }
    return valids;
    
};
function solve_singels() {
    var prev_sudoku = board.slice()
    while (true){
        for (let i = 0; i <9; i++) {
            for (let j = 0; j <9; j++) {
                var valids = get_valids(i,j);
                if (valids.length == 1){
                    board[i][j] = valids[0];
                }
            }
        }
        if (board.every((val,index) => val === prev_sudoku[index])){
            return board;
        }else{
            prev_sudoku = board.slice();
        }
    }
};
function vec_od_nic(val) {
    return val!=0;
}
function solve(){
    if (board.every(vec_od_nic)){
        console.log("Solved");
        console.log(board);
        return
    }
    for(let i = 0;i<=9;i++){
        for(let j = 0;j<=9;j++){
            if (board[i][j] == 0){
                var valids = get_valids(i,j);
                if (valids.length != 0){
                    for(var valid of valids){
                        board[i][j] = valid;
                        solve();
                        board[i][j] = 0;
                    }
                }
                return;
            }
        }
    }
}
solve_singels(board);
solve();