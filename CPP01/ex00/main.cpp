/*
	CUANDO INICIALIZAR LOS OBJETOS EN EL STACK O CUANDO EN EL HEAP
	STACK
		- Eficiencia en tiempo de vida: los objetos en el stack se crean y se destruyen automaticamente con su alcance (generalmente al salir del bloque de codigo donde se definen). Por lo tanto, no es necesario preocuprse por la gestion manual de la memoria.
		- Velocidad: la asignacion y liberacion de memoria en el stack es generalmente mas rapida que en el heap, ya que solo implica mover el puntero de pila.
		- Objetos pequeños: los objetos pequeños que no requieren de mucho especio se pueden almacenar facilmente en el stack sin preocuparse por el desbordamiento de memoria.
		- Alcance local: si el pobjeto solo se necesita dentro de un ambito local, y no necesita estar fuera de el, es mejor usar el stack.
	HEAP
		- Duracion mas alla del ambito local: si necesitamos que un objeto persista mas alla del ambito donde se crea, debes usar el heap.
		- Tamaño dinamico: si el tamaño de del objeto no se conoce en tiempo de compilacion o es grande, el heap es mas adecuado. El stack generalmente tiene un tamaño limitado y la memoria se asigna en tiempo de compilacion, lo que dificulta la creacion de objetos grandes.
		- Almacenamiento poliformico: si necesitamos utilizar poliformismos, los objetos deben alojarse en el heap mediante punteros para permnitir que las clases derivadas se manipulen a traves de piuntoero o referencia de la clase base.
		Ciclo de vida incierto:i si el tiempo de vida no se puede determinar con certeza, o puede cambiar dinamicamente en tiempo de ejeucion.
	
	Cabe destacar que en la mayoria de soluciones se implementan ambos.
*/

#include "Zombie.hpp"

int	main( void ) {
	Zombie*	heapZombie = newZombie("Quino");
	heapZombie->announce();
	delete heapZombie;
	randomChump("Mi inquilino");
	return 0;
}