#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main() {
system("chcp 65001");
    
    // Precios por categoría
    const double PRECIO_GENERAL = 10000;
    const double PRECIO_VIP = 20000;
    const double PRECIO_PLATINO = 35000;
    
    const int MAX_UNIDADES = 5;
    const double IMPUESTO = 0.13; // 13%
    
    // Acumuladores estadísticos
    int totalGeneral = 0, totalVIP = 0, totalPlatino = 0;
    double montoGeneral = 0, montoVIP = 0, montoPlatino = 0;
    
    char continuar;
    
    do {
        string nombre;
        int categoria;
        int cantidad;
        double precioUnitario = 0;
        
        cout << "\n===== REGISTRO DE VENTA =====\n";
        
        cout << "Nombre del comprador: ";
        cin.ignore();
        getline(cin, nombre);
        
        // Mostrar categorías
        cout << "\nCategorias disponibles:\n";
        cout << "1. General - \u20A1" << PRECIO_GENERAL << endl;
        cout << "2. VIP - \u20A1" << PRECIO_VIP << endl;
        cout << "3. Platino - \u20A1" << PRECIO_PLATINO << endl;
        
        // Validación de categoría
        do {
            cout << "Seleccione categoria (1-3): ";
            cin >> categoria;
            
            if (categoria < 1 || categoria > 3) {
                cout << "Categoria invalida. Intente nuevamente.\n";
            }
            
        } while (categoria < 1 || categoria > 3);
        
        // Asignar precio según categoría
        if (categoria == 1)
            precioUnitario = PRECIO_GENERAL;
        else if (categoria == 2)
            precioUnitario = PRECIO_VIP;
        else
            precioUnitario = PRECIO_PLATINO;
        
        // Validación de cantidad
        do {
            cout << "Cantidad de entradas (Maximo " << MAX_UNIDADES << "): ";
            cin >> cantidad;
            
            if (cantidad <= 0 || cantidad > MAX_UNIDADES) {
                cout << "Cantidad invalida. Intente nuevamente.\n";
            }
            
        } while (cantidad <= 0 || cantidad > MAX_UNIDADES);
        
        // Cálculos
        double subtotal = precioUnitario * cantidad;
        double impuesto = subtotal * IMPUESTO;
        double total = subtotal + impuesto;
        
        // Acumular estadísticas
        if (categoria == 1) {
            totalGeneral += cantidad;
            montoGeneral += total;
        } else if (categoria == 2) {
            totalVIP += cantidad;
            montoVIP += total;
        } else {
            totalPlatino += cantidad;
            montoPlatino += total;
        }
        
        // Mostrar resumen
        cout << "\n===== RESUMEN DE TRANSACCION =====\n";
        cout << "Comprador: " << nombre << endl;
        cout << "Cantidad: " << cantidad << endl;
        cout << "Precio unitario: \u20A1" << precioUnitario << endl;
        cout << "Subtotal: ¢" << subtotal << endl;
        cout << "Impuesto (13%): \u20A1" << impuesto << endl;
        cout << "Total a pagar: \u20A1" << total << endl;
        
        cout << "\nDesea registrar otra venta? (s/n): ";
        cin >> continuar;
        
    } while (continuar == 's' || continuar == 'S');
    
    
    // Mostrar estadísticas finales
    cout << "\n===== ESTADISTICAS FINALES =====\n";
    
    cout << "\nCategoria General:\n";
    cout << "Entradas vendidas: " << totalGeneral << endl;
    cout << "Monto recaudado: \u20A1" << montoGeneral << endl;
    
    cout << "\nCategoria VIP:\n";
    cout << "Entradas vendidas: " << totalVIP << endl;
    cout << "Monto recaudado: \u20A1" << montoVIP << endl;
    
    cout << "\nCategoria Platino:\n";
    cout << "Entradas vendidas: " << totalPlatino << endl;
    cout << "Monto recaudado: \u20A1" << montoPlatino << endl;
    
    // Uso de for para mostrar total general
    int totalEntradas = 0;
    int arreglo[3] = {totalGeneral, totalVIP, totalPlatino};
    
    for (int i = 0; i < 3; i++) {
        totalEntradas += arreglo[i];
    }
    
    cout << "\nTotal general de entradas vendidas: " << totalEntradas << endl;
    
    cout << "\nPrograma finalizado.\n";
    
    return 0;
}
