bool Pieces::King() {
    //HERE ADD IF CASTLING
    if (abs(src_col - dest_col) > 1) { return false; }//king can move only one step
    if (whosTurn()) {//white turn
        if (islower(dest_val)) { return false;}
        
//        if (src_row == 7) {
//            for (int i = src_row; i >= src_row - 1; --i) {
//                for (int j = src_col - 1; j <= src_col + 1; ++j) {
//                    cout << kingScan[i][j];
//                }
//                cout << endl;
//            }
//            return true;
//        }
//        if (src_row == 0) {
//            for (int i = src_row + 1; i > src_row - 1; --i) {
//                for (int j = src_col - 1; j <= src_col + 1; ++j) {
//                    cout << kingScan[i][j];
//                }
//                cout << endl;
//            }
//            return true;
//        } else {
//            for (int i = src_row + 1; i >= src_row - 1; --i) {
//                for (int j = src_col - 1; j <= src_col + 1; ++j) {
//                    cout << kingScan[i][j];
//                }
//                cout << endl;
//            }
//            return true;
//        }
    }
//    else//black's turn
//    {
//            if (src_row == 7){
//                for (int i = src_row; i >= src_row-1 ; --i) {
//                    for (int j = src_col-1; j <= src_col+1; ++j) {
//                        cout << kingScan[i][j];
//
//                    }
//                    cout <<endl;
//                }
//                return true;
//            }
//            if ( src_row == 0)
//            {
//                for (int i = src_row+1; i > src_row-1 ; --i) {
//                    for (int j = src_col-1; j <= src_col+1; ++j) {
//                        cout << kingScan[i][j];
//                    }
//                    cout <<endl;
//                }
//                return true;
//            }
//            else
//            {
//                for (int i = src_row+1; i >= src_row-1 ; --i) {
//                    for (int j = src_col-1; j <= src_col+1; ++j) {
//                        cout << kingScan[i][j];
//                    }
//                    cout <<endl;
//                }
//                return true;
//            }
//        }
//    }