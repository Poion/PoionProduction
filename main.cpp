#include "funz_gioco.h"

const float FPS = 60;
using namespace std;
int main(int argc, char const *argv[]) {
        strumenti tool;
        personaggio pg;
        std::cout << "dio" << '\n';
        initz(tool,pg,FPS);

        std::cout << "dio" << '\n';
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
