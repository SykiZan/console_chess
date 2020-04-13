#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//function to draw board
void display_board(vector< vector<string> > vec)
{
     cout<<endl<<endl;
     cout<<"          white"<<endl;
     cout<<"   A  B  C  D  E  F  G  H"<<endl;
     for(int i = 0; i < vec.size(); ++i)
      {
          if( i % 2 != 0)
              cout<< i/2 + 1;
          else
             cout<<" ";    
          
          for( int j = 0; j < vec.at(i).size(); ++j)
          {
               cout<<vec.at(i).at(j);
               
               if( j % 24 == 0 && j !=0 && i %2 !=0)
                  cout<< i/2 + 1;
               
          }
           
        cout<<endl;
      }
      cout<<"   A  B  C  D  E  F  G  H"<<endl;
      cout<<"          black"<<endl;
      cout<<endl<<endl;
}


int main()
{
     // vector containing each element of the board
     vector< vector<string> > board  ;
      vector< vector<string> > board_save  ;
     
     //line to build a horizontall wall
     vector <string> horz_line {"|","-","-","|","-","-","|","-","-","|","-","-","|","-","-",
                                "|","-","-","|","-","-","|","-","-","|"};
     
     //line to build empty row 
     vector <string> empty_line {"|"," "," ","|"," "," ","|"," "," ","|"," "," ","|"
                                 ," "," ","|"," "," ","|"," "," ","|"," "," ","|"};
     
     
      // we obviously have multiple rows so let's fill them into our board vector
      board.push_back(horz_line);
      board.push_back(empty_line);
      board.push_back(horz_line);
      board.push_back(empty_line);
      board.push_back(horz_line);
      board.push_back(empty_line);
      board.push_back(horz_line);
      board.push_back(empty_line);
      board.push_back(horz_line);
      board.push_back(empty_line);
      board.push_back(horz_line);
      board.push_back(empty_line);
      board.push_back(horz_line);
      board.push_back(empty_line);
      board.push_back(horz_line);
      board.push_back(empty_line);
      board.push_back(horz_line);
      

      //Let's place figures into 1st row (white side)
      
      board.at(1).at(1) = "W";
      board.at(1).at(2) = "R";
      board.at(1).at(4) = "W";
      board.at(1).at(5) = "N";
      board.at(1).at(7) = "W";
      board.at(1).at(8) = "B";
      board.at(1).at(10) = "W";
      board.at(1).at(11) = "Q";
      board.at(1).at(13) = "W";
      board.at(1).at(14) = "K";
      board.at(1).at(16) = "W";
      board.at(1).at(17) = "B";
      board.at(1).at(19) = "W";
      board.at(1).at(20) = "N";
      board.at(1).at(22) = "W";
      board.at(1).at(23) = "R";
      
      //second row (white side)
      board.at(3).at(1) = "W";
      board.at(3).at(2) = "P";
      board.at(3).at(4) = "W";
      board.at(3).at(5) = "P";
      board.at(3).at(7) = "W";
      board.at(3).at(8) = "P";
      board.at(3).at(10) = "W";
      board.at(3).at(11) = "P";
      board.at(3).at(13) = "W";
      board.at(3).at(14) = "P";
      board.at(3).at(16) = "W";
      board.at(3).at(17) = "P";
      board.at(3).at(19) = "W";
      board.at(3).at(20) = "P";
      board.at(3).at(22) = "W";
      board.at(3).at(23) = "P";
      
      //second row (black side)
      
      board.at(13).at(1) = "B";
      board.at(13).at(2) = "P";
      board.at(13).at(4) = "B";
      board.at(13).at(5) = "P";
      board.at(13).at(7) = "B";
      board.at(13).at(8) = "P";
      board.at(13).at(10) = "B";
      board.at(13).at(11) = "P";
      board.at(13).at(13) = "B";
      board.at(13).at(14) = "P";
      board.at(13).at(16) = "B";
      board.at(13).at(17) = "P";
      board.at(13).at(19) = "B";
      board.at(13).at(20) = "P";
      board.at(13).at(22) = "B";
      board.at(13).at(23) = "P";
      
      //first black row
      board.at(15).at(1) = "B";
      board.at(15).at(2) = "R";
      board.at(15).at(4) = "B";
      board.at(15).at(5) = "N";
      board.at(15).at(7) = "B";
      board.at(15).at(8) = "B";
      board.at(15).at(10) = "B";
      board.at(15).at(11) = "Q";
      board.at(15).at(13) = "B";
      board.at(15).at(14) = "K";
      board.at(15).at(16) = "B";
      board.at(15).at(17) = "B";
      board.at(15).at(19) = "B";
      board.at(15).at(20) = "N";
      board.at(15).at(22) = "B";
      board.at(15).at(23) = "R";
      
       cout<<endl;
       
       display_board(board);
       
       //Moving pieces
       
     
       string col_ruler {"ABCDEFGH"}; // Need this to convert chars into numbers by finding char position
       vector<string> char_vec {"A","B","C","D","E","F","G","H"};
       vector<int> num_vec {1,2,3,4,5,6,7,8};
       //select piece to be moved
       string select_col ; //select column
       int select_row;     //select row
       
       //select cell to put piece on
       string move_col ;   //move column
       int move_row;       //move row
       
       int k = 1;
       
       int t = 0;        //need these guys to track turn
       
       bool wrong_turn {false};
       
       //for input validation purposes
       vector<string>::iterator it ; //select column
       vector<int>::iterator it_1 ; //select row
       vector<string>::iterator it_2 ; //move column
       vector<int>::iterator it_3 ; //move row
       
       while(true)
       {
           
           if( k % 2 == 1)
               cout<<"White player's turn"<<endl;
           else
               cout<<"Black player's turn"<<endl;    
            ++k;
            t = k;
       //Prompt player to feed coordinates of a piece and read them in
       cout<<"Select piece to move / 's' to save / 'l' to load / 'x' to end game"<<endl;
       cout<<"Select column (A-H) : ";
       cin>>select_col;
       for_each(select_col.begin(), select_col.end(), [](char & c) {
       c = ::toupper(c);
        });   // uppercasing input 
        
        
       if(select_col == "X")
           break;
       if(select_col == "S")
       {
            board_save = board;
            
       }
              
       if(select_col == "L")
       {
           board =board_save ; 
           --k;
       }
           
        //validate input   
       it = find(char_vec.begin(), char_vec.end(), select_col);
       if (it == char_vec.end())
       {
           --k;
           system("cls");
           cout<<"Invalid input, try again"<<endl;
           display_board(board);
           continue;
       }
       
       //Prompt player to feed coordinates of a cell and read them in
       cout<<"Select row (1-8) : ";
       cin>>select_row;
       
       //validate input
       it_1 = find(num_vec.begin(), num_vec.end(), select_row);
       if (it_1== num_vec.end())
       {
           --k;
           system("cls");
           cout<<"Invalid input, try again"<<endl;
           display_board(board);
           continue;
       }
       
       cout<<"Select column (A-H) to move pies to : ";
       cin>>move_col;
       for_each(move_col.begin(), move_col.end(), [](char & c) {
       c = ::toupper(c);
        });
        
      //validate input
       it_2 = find(char_vec.begin(), char_vec.end(), move_col);
       if (it_2 == char_vec.end())
       {
           --k;
           system("cls");
           cout<<"Invalid input, try again"<<endl;
           display_board(board);
           continue;
       }    
       
       
       cout<<"Select row (1-8) to move pies to : ";
       cin>>move_row;
       
       //validate input
       it_3 = find(num_vec.begin(), num_vec.end(), move_row);
       if (it_3== num_vec.end())
       {
           --k;
           system("cls");
           cout<<"Invalid input, try again"<<endl;
           display_board(board);
           continue;
       }
       
       // Transform our input so it can be proper coordinates of our 2D vector (board)
       int sr; //selected row coordinate
       int sc; //selected column coordinate
       
       sr = select_row * 2 - 1;
       sc = col_ruler.find(select_col) * 3 + 1;
       
       int mr; //movw to row (coordinate of cell's row)
       int mc; //move to column (coordinate of cell's column
       
       mr = move_row * 2 - 1;
       mc = col_ruler.find(move_col) * 3 + 1;
       
       //Validating pieces moves
       
       if(board.at(sr).at(sc) != "B" && (k % 2 == 1))
       { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
            --k;
            wrong_turn= true;
        }
       else  if(board.at(sr).at(sc) != "W" && (k % 2 == 0))
       { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
            --k;
            wrong_turn = true;
        }
        
       //Pawn + couple general cases
       else if(board.at(sr).at(sc) == "W" && board.at(mr).at(mc) == "W") // forbid capturing your own pieces
        { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
            --k;
        }
        else if(board.at(sr).at(sc) == " " ) // forbid moving empty cells 
        { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
            --k;
        }
       else if(board.at(sr).at(sc) == "B" && board.at(mr).at(mc) == "B") // forbid capturing your own pieces
        { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
            --k;
        } 
        else if(board.at(sr).at(sc+1) == "P" && board.at(sr).at(sc) == "W" && (mr < sr)) //forbid white pawn to move backwards
        { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
            --k;
        } 
        else if(board.at(sr).at(sc+1) == "P" && board.at(sr).at(sc) == "B" && (mr > sr)) //forbid black pawn to move backwards
        { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
            --k;
        }
        
       else if((board.at(sr).at(sc+1) == "P" && ((mc - sc) != 0 )
                                         && ( ( board.at(sr).at(sc) == "W") && (board.at(mr).at(mc) !="B"
                                         || (board.at(mr).at(mc) ==" ") ))
                                         && ((mr - sr) >= 2) && ((mc - sc) % 3 ==0 ) ))// allow  diagonal capture
        { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
           --k;
        }
        else if((board.at(sr).at(sc+1) == "P" && ((mc - sc) != 0 )
                                         && ( ( board.at(sr).at(sc) == "B") && (board.at(mr).at(mc) !="W"
                                         || (board.at(mr).at(mc) ==" ") ))
                                         && ((mr - sr) <= -2) && ((mc - sc) % 3 ==0 ) ))// allow  diagonal capture
        { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
           --k;
        }
        else if(board.at(sr).at(sc+1) == "P" && (mr == sr) ) // forbid right/left moves
        { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
            --k;
           
        }  
        else if(board.at(sr).at(sc+1) == "P" && ((mr - sr) > 2 && sr != 3  )) // allow to move 2 rows if it's 1st pawn's move
        { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
            --k;
           
        }  
        else if(board.at(sr).at(sc+1) == "P" && ((mr - sr) < -2 && sr != 13  )) // allow to move 2 rows if it's 1st pawn's move
        { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
            --k;
           
        }

                                  
        else if(board.at(sr).at(sc+1) == "P" && (sr == 3 && (mr - sr) > 4 ))  // allow to move 2 rows if it's 1st pawn's move
        { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
            --k;
        } 
        else if(board.at(sr).at(sc+1) == "P" && (sr == 13 && (mr - sr) < -4 ))  // allow to move 2 rows if it's 1st pawn's move
        { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
            --k;
        } 
 
            
        else if(board.at(sr).at(sc+1) == "P" && ( board.at(sr).at(sc) == "W") && (board.at(mr).at(mc) =="B")
                                              && ((mc - sc) % 3 == 0) && ((mr - sr) !=2) ) // forbid right or left capturing
        { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
            --k;
        }  
       else if(board.at(sr).at(sc+1) == "P" && ( board.at(sr).at(sc) == "B") && (board.at(mr).at(mc) =="W")
                                              && ((mc - sc) % 3 == 0) && ((mr - sr) != - 2) ) // forbid right or left capturing
        { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
            --k;
        }       
 
       else if(board.at(sr).at(sc+1) == "P" && ( board.at(sr).at(sc) == "W") && (board.at(mr).at(mc) =="B")
                                              && ((mc - sc) > 3 || (mc - sc) < -3) )
                                               
        { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
            --k;
        }  
        else if(board.at(sr).at(sc+1) == "P" && ( board.at(sr).at(sc) == "B") && (board.at(mr).at(mc) =="W")
                                              && ((mc - sc) < -3 || (mc - sc) > 3)) 
        { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
            --k;
        }                                           
        else if (board.at(sr).at(sc+1) == "P" && ( board.at(sr).at(sc) == "W") && (board.at(mr).at(mc) =="B")
                                              && ((mc - sc) == 0))
        { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
            --k;
        }
        else if (board.at(sr).at(sc+1) == "P" && ( board.at(sr).at(sc) == "B") && (board.at(mr).at(mc) =="W")
                                              && ((mc - sc) == 0))
        { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
            --k;
        }
        
        //Rook
        else if (board.at(sr).at(sc+1) == "R" && (select_row == move_row) && (select_col == move_col))
        { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
            --k;
        }
        else if (board.at(sr).at(sc+1) == "R" && (select_col != move_col) && (select_row != move_row))
        { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
            --k;
        }
        
        //Bishop col_ruler.find(select_col)
        else if (board.at(sr).at(sc+1) == "B" &&
                ! ( move_row - select_row == (col_ruler.find(move_col) - col_ruler.find(select_col))
                || move_row - select_row == (col_ruler.find(select_col) - col_ruler.find(move_col))))
       { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
            --k;
        }   
           //Knight                                                       
  
       else if(board.at(sr).at(sc+1) == "N" && (move_row - select_row > 2 || move_row - select_row < -2
                                            || static_cast<int>(col_ruler.find(move_col) - col_ruler.find(select_col)) >2
                                            || static_cast<int>(col_ruler.find(move_col) - col_ruler.find(select_col)) <-2))
          { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
            --k;
          }                                          
    else if(board.at(sr).at(sc+1) == "N" &&(move_row - select_row == 2 || move_row - select_row ==-2)
                                         && !( (static_cast<int>(col_ruler.find(move_col) - col_ruler.find(select_col)) ==1
                                         || static_cast<int>(col_ruler.find(move_col) - col_ruler.find(select_col)) ==-1)))
    { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
            --k;
    }                                         
    else if(board.at(sr).at(sc+1) == "N" &&((static_cast<int>(col_ruler.find(move_col) - col_ruler.find(select_col)) ==2
                                             || static_cast<int>(col_ruler.find(move_col) - col_ruler.find(select_col)) ==-2)
                                             && !(move_row - select_row == 1 || move_row - select_row ==-1)))
     { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
            --k;
    } 
        else if(board.at(sr).at(sc+1) == "N" &&((static_cast<int>(col_ruler.find(move_col) - col_ruler.find(select_col)) ==1
                                             || static_cast<int>(col_ruler.find(move_col) - col_ruler.find(select_col)) ==-1)
                                             && !(move_row - select_row == 2 || move_row - select_row ==-2)))
     { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
            --k;
    }  
    else if(board.at(sr).at(sc+1) == "N" &&(move_row - select_row == 1 || move_row - select_row ==-1)
                                         && !( (static_cast<int>(col_ruler.find(move_col) - col_ruler.find(select_col)) ==2
                                         || static_cast<int>(col_ruler.find(move_col) - col_ruler.find(select_col)) ==-2)))
    { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
            --k;
    }   
     //King
      else if(board.at(sr).at(sc+1) == "K" &&( move_row - select_row > 1 || move_row - select_row <-1
                                           || static_cast<int>(col_ruler.find(move_col) - col_ruler.find(select_col)) >1
                                           || static_cast<int>(col_ruler.find(move_col) - col_ruler.find(select_col)) <-1 ))
    { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
            --k;
    }  
    // Queen
    else if(board.at(sr).at(sc+1) == "Q" && !((select_row == move_row) &&(select_col != move_col))
                                         &&  !((select_row != move_row) &&(select_col == move_col))
                                         && !(select_row - move_row == static_cast<int>(col_ruler.find(move_col) - col_ruler.find(select_col)))
                                         && !(move_row - select_row == static_cast<int>(col_ruler.find(move_col) - col_ruler.find(select_col))))
    { 
           system("cls");
           cout<<"Wrong move"<<endl;
           display_board(board);
            --k;
    } 
    
    
       else
       {
       // Perform the move =). 
       board.at(mr).at(mc) = board.at(sr).at(sc);
       board.at(mr).at(mc+1) = board.at(sr).at(sc+1);
       board.at(sr).at(sc) = " ";
       board.at(sr).at(sc+1) = " ";
       
       
       
       system("cls");
       
       cout<<"Move was sucsessful"<<endl;
      
       
       display_board(board);
       
       }
        
       if( wrong_turn) 
            cout<<"It's another player's turn ."; 
       wrong_turn = false;
       cout<<"Previous move : "<<select_col<<select_row<<" to "<<move_col<<move_row<<" : ";
       if(t>k)
           cout<<"Invalid move try again"<<endl;
       
       else
       {
           cout<<"Move was sucsessful"<<endl;
                 
       } 



 }

 return 0;  
}


  