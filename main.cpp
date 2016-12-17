#include "funz_gioco.h"

const float FPS = 60;
using namespace std;
int main(int argc, char const *argv[]) {
        strumenti tool;
        personaggio pg;
        initz(tool,pg,FPS);

        if(tool.controllo == -1)
                return tool.controllo;
        else
                cout<<"funge!"<<endl;
        while(!tool.doexit) {

                start(tool,pg);
        }
        sudoku(tool,pg);

        return 0;
}
