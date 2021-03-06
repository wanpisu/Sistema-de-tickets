#ifndef FINANCIERO_H
#define FINANCIERO_H
#include "Cliente.h"
#include "Producto.h"
#include "Ticket.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <sstream>

///Informa que no se encontr� un resultado
#define no_encontrado -1

/// Criterios para ordenar
///Primera linea clientes, segunda tickets y tercera clientes
enum CriterioOrden { por_nombre, por_apellido, por_alias, por_mail, por_direccion, por_telefono, por_dni, 
					por_id, por_fecha, por_dni_t, por_cod_prod,
					por_pnombre, por_pmarca, por_pcodigo, por_pvalor, por_pdescripcion };

class Financiero {
public:
	Financiero(); ///Cuando inicia, carga todos los tickets, clientes y productos desde los archivos binarios
	
	Cliente &SeleccionarCliente(int i); ///Tomamos un cliente para poder manipularlo
	void CargarClientes(std::string); ///Realiza la carga de todos los clientes desde un archivo binario
	void AgregarCliente(Cliente); ///Agrega un cliente
	void EliminarCliente(int); ///S�LO PARA MI	
	void GuardarClientes(); ///Guarda todas las modificaciones efectuadas (agregar/eliminar/modificar)
	int CantidadClientes() const; ///Informa la cantidad de clientes disponibles
	std::vector<int> MostrarClientesHabilitados(); ///Muestra posici�n de clientes habilitados para true

	
	Producto &SeleccionarProducto(int i);
//	void GenerarProducto(std::string, std::string, std::string, std::string, float); ///Genera un product COMPLETO, luego se agrega al listado con AgregarProducto
	void CargarProductos(std::string); ///Cargama desde el archivo binario los datos de todos los productos
	void AgregarProducto(Producto); ///Agrega un producto
	void EliminarProducto(int); ///Elimina un producto
	void GuardarProductos(); ///Guarda todas las modificaciones efectuadas (agregar/eliminar/modificar)
	int CantidadProductos() const; ///Retorna la cantidad de productos que poseemos en la DB
	std::vector<std::string> ListarCodProd(); ///Lista c�digos en USO, no todos los existentes
	std::string prod_GenerarCodBarras(); ///No se usa, ahora se genera por c�digo de barras real
	
	
	Ticket &SeleccionarTicket(int i);
	void CargarTickets(std::string); ///Cargama desde el archivo binario los datos de todos los tickets
	void AgregarTicket(Ticket); ///Agrega el ticket al vector actual de de tickets, luego lo almacena en el archivo binario
	void GuardarTicketsBin(); ///Guarda los tickets almacenados en el vector de tickets en proceso en el archivo binario DB
	void EliminarTicket(int); ///Elimina un ticket. Primero lo hace del vector actual
	int CantidadTickets() const; ///Retorna la cantidad de tickets que poseemos
	float TotalTicket(std::string);///Muestra el monto total vendido por un ticket
	void ImprimirTicket(std::string); ///Imprimimos en txt el c�digo de ticket que pasemos
									///Le pasamos el c�digo de ticket a buscar
	std::string ticket_GenerarId(); ///Busca en el archivo TXT el �ltimo ID de ticket y le s�ma +1 para generar uno nuevo
	std::string ticket_VerUltimoIdString(); ///Retorna el �ltimo ID
	int ticket_VerUltimoIdInt(); ///S�lo para corroborar, no tiene uso
	std::vector<std::string> IdTicketsNoRepetidos(); ///Unifica los c�digos repetidos
	struct Cl_Pr_Tk MostrarTicket(std::string);///Muestra toda la info de un ticket
	
	
	
	int BuscarNombre(std::string); ///Busqueda por nombre
	int BuscarApellido(std::string); ///Busqueda por apellido
	int BuscarAlias(std::string); ///Busqueda por alias
	int BuscarMail(std::string); ///Busqueda por mail
	int BuscarDireccion(std::string); ///Busqueda por direcci�n
	int BuscarTelefono(std::string); ///Busqueda por n�mero telef�nico
	int BuscarDni(std::string); ///CON ESTO MOSTRAMOS LOS DATOS DEL COMPRADOR
	int BuscarCodProd(std::string); ///CON ESTO MOSTRAMOS LOS DATOS DEL PRODUCTO
	int BuscarNombreProd(std::string);
	int BuscarMarcaProd(std::string);
	int BuscarIdTicket(std::string);
	
	void Ordenar(CriterioOrden);///Orden para clientes / productos / tickes
	
private:
	std::vector<Cliente> m_clientes;
	std::vector<Producto> m_productos;
	std::vector<Ticket> m_tickets;
};

#endif

