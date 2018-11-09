#include <iostream>
#include<stack>
#include<vector>
#include<queue>

using namespace std;


bool BusquedaVector(vector<int> ruta,int numero) 
{
	for (int x = 0; x < ruta.size(); x++) 
	{
		if (ruta[x] == numero) 
		{
			return true;
		}
	}
	return false;
}

bool BusquedaPila(stack<int> miPila, int numero)
{
	stack <int> aux = miPila;
	for (int x = 0; x < miPila.size(); x++)
	{
		if (aux.top() == numero)
		{
			return true;
		}
		aux.pop();
	}
	return false;
}

bool BusquedaCola(queue<int> miCola, int numero)
{
	queue <int> aux = miCola;
	for (int x = 0; x < miCola.size(); x++)
	{
		if (aux.front() == numero)
		{
			return true;
		}
		aux.pop();
	}
	return false;
}


int main() 
{

	int arreglo[4][4]{ {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
	bool  conectado = false;

	stack<int> miPila; // Pila utilizada para busqueda de profundidad
	queue<int> miCola; // Pila utilizada para busqueda de anchura
	vector<int> ruta,ruta2;


	for (int x = 0; x<sizeof(arreglo) / sizeof(arreglo[0]); x++) 
	{
		for (int y = 0; y<sizeof(arreglo) / sizeof(arreglo[0]); y++)
		{
			conectado = false;
			cout << "El noodo: " << x << " esta conectado con: " << y <<" ?"<< endl;
			cin >>conectado;
			if (conectado) 
			{
				arreglo[x][y] = 1;
			}

		}
	}

	cout << endl;
	for (int x = 0; x<sizeof(arreglo) / sizeof(arreglo[0]); x++)
	{
		cout << "El nodo " << x << " esta conectado con ";
		for (int y = 0; y<sizeof(arreglo) / sizeof(arreglo[0]); y++)
		{
			if (arreglo[x][y] == 1) 
			{
				cout << y << " ";
			}
		}
		cout<<endl;
	}

	cout << endl;

	for (int x = 0; x<sizeof(arreglo) / sizeof(arreglo[0]); x++)
	{
		cout << "Los nodos ";
		for (int y = 0; y<sizeof(arreglo) / sizeof(arreglo[0]); y++)
		{
			if (arreglo[x][y] == 1)
			{
				cout << y << " ";
			}
		}
	    cout << " esta conectado con "<<x<<endl;
	}

	cout << endl;

	for (int x = 0; x<sizeof(arreglo) / sizeof(arreglo[0]); x++)
	{
		for (int y = 0; y<sizeof(arreglo) / sizeof(arreglo[0]); y++)
		{
			cout << arreglo[x][y] <<" ";
		}
		cout << endl;
	}

	cout << endl << endl;
	
	int inicio;
	cout << "Indica por cual nodo quieres empezar: " << endl;
	cin >> inicio;
	
	for (int x = 0; x < sizeof(arreglo) / sizeof(arreglo[0]); x++)
	{
		ruta.push_back(inicio);
		for (int y = 0; y < sizeof(arreglo) / sizeof(arreglo[0]); y++)
		{
			if (arreglo[inicio][y] == 1)
			{
				if (!BusquedaPila(miPila, y) && !BusquedaVector(ruta, y)) 
				{
					miPila.push(y);
				}
			}
		}
		if (miPila.size() > 0) 
		{
			inicio = miPila.top();
			miPila.pop();
		}
	
	}

	cout << endl << "Metodo de profundidad" << endl;
	for (int x = 0; x < ruta.size(); x++) 
	{
		cout << ruta[x] << " ";
	}



	cout << endl << "Indica por cual nodo quieres empezar: " << endl;
	cin >> inicio;

	for (int x = 0; x < sizeof(arreglo) / sizeof(arreglo[0]); x++)
	{
		ruta2.push_back(inicio);
		for (int y = 0; y < sizeof(arreglo) / sizeof(arreglo[0]); y++)
		{
			if (arreglo[inicio][y] == 1)
			{
				if (!BusquedaCola(miCola, y) && !BusquedaVector(ruta2, y))
				{
					miCola.push(y);
				}
			}
		}
		if (miCola.size() > 0)
		{
			inicio = miCola.front();
			miCola.pop();
		}

	}

	cout << endl << "Metodo de anchura" << endl;
	for (int x = 0; x < ruta.size(); x++)
	{
		cout << ruta2[x] << " ";
	}


	cout << endl;
	system("pause");
}