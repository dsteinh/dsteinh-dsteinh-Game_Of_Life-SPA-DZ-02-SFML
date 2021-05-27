#include "game_of_life.h"
#include<ctime>
#include <SFML/Graphics.hpp>
game_of_life::game_of_life()
{
   // srand(time(nullptr));
    for (unsigned i = 0; i < REDAKA; i++)
    {

        for (unsigned j = 0; j < STUPACA; j++)
        {
            _generacija[i][j] = false;
            
        }
       
    }

    
}

/*bool game_of_life::slucajna_vrijednost()
{
    int n = rand() % (max - min + 1) - min;
    if (n <= 25)
    {
    return true;

    }
    else {
        return false;
    }
}
*/


int game_of_life::koliko_susjeda(int i, int j)
{
    int offseti[] = { -1,-1,0,1,1,1,0,-1 };
    int offsetj[] = { 0,1,1,1,0,-1,-1,-1 };
    
    int sum = 0;
    
    for (int k = 0; k < 8; k++)
    {
        int ni = i + offseti[k];
        int nj = j + offsetj[k];
        if (ni < 0 || ni > REDAKA-1 || nj < 0 || nj > STUPACA-1)
        {
            continue;
        }
       
        
            sum = sum + _generacija[ni][nj];


    }
    
    
    return sum;
}


void game_of_life::sljedeca_generacija()
{
    for (unsigned i = 0; i < REDAKA; i++)
    {
        for (unsigned j = 0; j < STUPACA; j++)
        {
           

            if (_generacija[i][j] == true && (koliko_susjeda(i, j) == 2 || koliko_susjeda(i, j) == 3))
            {
                _sljedeca_generacija[i][j] = true;
            }
            else if (_generacija[i][j] == true && koliko_susjeda(i, j) < 2 )
            {
                _sljedeca_generacija[i][j] = false;
            }
            else if (_generacija[i][j] == false && koliko_susjeda(i, j) == 3)
            {
                _sljedeca_generacija[i][j] = true;
            }
            else if (_generacija[i][j] == true && koliko_susjeda(i, j) > 3)
            {
                _sljedeca_generacija[i][j] = false;
            }
            else
            {
                _sljedeca_generacija[i][j] = _generacija[i][j];
            }
            
            
           
        }
           
        

    }
   
    for (unsigned i = 0; i < REDAKA; i++)
    {

        for (unsigned j = 0; j < STUPACA; j++)
        {
          
            _generacija[i][j] = _sljedeca_generacija[i][j];
        }
      
    }
}

void game_of_life::iscrtaj(std::vector<std::vector<sf::RectangleShape>>& grid)
{
  

    for (unsigned i = 0; i < REDAKA; i++)
    {

        for (unsigned j = 0; j < STUPACA; j++)
        {
            switch (_generacija[i][j])
            {
            case true: grid[i][j].setFillColor(sf::Color::White);
               
                break;

            case false: grid[i][j].setFillColor(sf::Color::Black);
               
                break;
            }

        }
        cout << endl;
    }
   
  
}

void game_of_life::set_generacija(int i, int j)
{
    _generacija[i][j] = true;
}

unsigned game_of_life::get_generacija_x()
{
    for (unsigned i = 0; i < REDAKA; i++)
    {
        for (unsigned j = 0; j < STUPACA; j++)
        {

        if (_generacija[i][j] == true)
        {
            return i;
        }
        }
    }
    
}

unsigned game_of_life::get_generacija_y()
{

    for (unsigned i = 0; i < REDAKA; i++)
    {
        for (unsigned j = 0; j < STUPACA; j++)
        {

            if (_generacija[i][j] == true)
            {
                return j;
            }
        }
    }
}
