#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstring>
#include <unistd.h>//Uso de la funcion sleep o usleep
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include <ctime>


int opcion;
int i;

struct deducciones{
	float INSS_deu;
	float IR_deu;
	float otrosDescuentos;
	float anticiposS;
	float totaldeducciones;
	float PagaTotal;
};

struct ingresos{
	float salariobruto;
	float aguinaldo;
	float feriados;
	float antiguedad;
	int vacacionesdias;
	float vacacionestotal;
	float subsidio;
	int subsidiodia;
	int horascantidad;
	float horasmonto;
	float salarioing;
	float totalingresos;
	struct deducciones aux1;
};


struct principal{
	
	int llave;
	std::string diasing;
	std::string mesing;
	std::string anioing;
	std::string nombre;
	std::string apellido;
	std::string cargo;
	std::string area;
	std::string seccion;
	std::string cedula;
	int dias;
	std::string numinss;
	std::string fechaing;
	float vacaciones;
	struct ingresos aux2;
	
}dat[100],datoMod;

using namespace std;

float salarioprima(int q){
    
	for(i=q;i<5;i++){
		dat[i].aux2.salarioing=(dat[i].aux2.salariobruto/30)*dat[i].dias;
		return dat[i].aux2.salarioing;
	}
	
}

float horasextra(int q2){
	float saldodia=0,saldohora=0,saldoordi=0;
	for(i=q2;i<2;i++){
		saldodia=dat[i].aux2.salariobruto/30;
		saldohora=saldodia/8;
		saldoordi=saldohora*2;
		dat[i].aux2.horasmonto=saldoordi*dat[i].aux2.horascantidad;
		return dat[i].aux2.horasmonto;
	}

}

float vacaciones(int q3){
	for(i=q3;i<2;i++){
	
		if(dat[i].aux2.vacacionesdias==30){
		dat[i].aux2.vacacionestotal=dat[i].aux2.salarioing;
		return dat[i].aux2.vacacionestotal;	
		}
		
		if(dat[i].aux2.vacacionesdias==15){
			dat[i].aux2.vacacionestotal=dat[i].aux2.salariobruto/2;
			return dat[i].aux2.vacacionestotal;
		}
		else{
			dat[i].aux2.vacacionestotal=(dat[i].aux2.salariobruto/30)*dat[i].aux2.vacacionesdias;
			return dat[i].aux2.vacacionestotal;
		}	
	}
}


float feriados(int q6){
	float total1=0,tiempo2=0,total2;
	int tiempo;
	string mes;
	
	time_t rawtime;
  	struct tm * timeinfo;
  	char buffer[80];

  	time (&rawtime);
  	timeinfo = localtime(&rawtime);

  	strftime(buffer,sizeof(buffer),"%d-%m-%Y",timeinfo);
  	
	string str(buffer);
	
	mes=str.substr(3,2);
	
	cout<<mes;
	
	if(mes=="01"){
		tiempo=1;
		for(i=q6;i<2;i++){
		total1=(dat[i].aux2.salarioing/30);
		total2=total1*2;
		return dat[i].aux2.feriados=total2*tiempo;
		}
	}
	
	if(mes=="02"){
		tiempo=0;
		for(i=q6;i<2;i++){
		total1=(dat[i].aux2.salarioing/30);
		total2=total1*2;
		return dat[i].aux2.feriados=total2*tiempo;
		}	
	}
	
	if(mes=="03"){
		tiempo=3;
		for(i=q6;i<2;i++){
		total1=(dat[i].aux2.salarioing/30);
		total2=total1*2;
		return dat[i].aux2.feriados=total2*tiempo;
		}	
		
	}
	
	if(mes=="04"){
		tiempo=0;
		for(i=q6;i<2;i++){
		total1=(dat[i].aux2.salarioing/30);
		total2=total1*2;
		return dat[i].aux2.feriados=total2*tiempo;
		}	
	}
	
	if(mes=="05"){
		tiempo=1;
		for(i=q6;i<2;i++){
		total1=(dat[i].aux2.salarioing/30);
		total2=total1*2;
		return dat[i].aux2.feriados=total2*tiempo;
		}	
	}
	
	if(mes=="06"){
		tiempo=0;
		for(i=q6;i<2;i++){
		total1=(dat[i].aux2.salarioing/30);
		total2=total1*2;
		return dat[i].aux2.feriados=total2*tiempo;
		}		
	}
	
	if(mes=="07"){
		tiempo=1;
		for(i=q6;i<2;i++){
		total1=(dat[i].aux2.salarioing/30);
		total2=total1*2;
		return dat[i].aux2.feriados=total2*tiempo;
		}	
	}
	
	if(mes=="08"){
		tiempo=1;
		for(i=q6;i<2;i++){
		total1=(dat[i].aux2.salarioing/30);
		total2=total1*2;
		return dat[i].aux2.feriados=total2*tiempo;
		}	
	}
	
	if(mes=="09"){
		tiempo=2;
		for(i=q6;i<2;i++){
		total1=(dat[i].aux2.salarioing/30);
		total2=total1*2;
		return dat[i].aux2.feriados=total2*tiempo;
		}
		
	}
	
	if(mes=="10"){
		tiempo=0;
		for(i=q6;i<2;i++){
		total1=(dat[i].aux2.salarioing/30);
		total2=total1*2;
		return dat[i].aux2.feriados=total2*tiempo;
		}
	}
	
	if(mes=="11"){
		tiempo=0;
		for(i=q6;i<2;i++){
		total1=(dat[i].aux2.salarioing/30);
		total2=total1*2;
		return dat[i].aux2.feriados=total2*tiempo;
		}	
	}
	
	if(mes=="12"){
		tiempo=2;
		for(i=q6;i<2;i++){
		total1=(dat[i].aux2.salarioing/30);
		total2=total1*2;
		return dat[i].aux2.feriados=total2*tiempo;
		}	
		
	}
	
}

float INSS_deduccion(int q8){
	
	for(i=q8;i<2;i++){
		dat[i].aux2.aux1.INSS_deu=dat[i].aux2.salariobruto*0.0625;
		return dat[i].aux2.aux1.INSS_deu;
	}
}

float aguinaldo(int q5){
	
	int diaentero;
	int mesentero;
	int anioentero;
	float sal_total_meses=0;
	float sal_total_dias=0;
	
	for(i=q5;i<2;i++){
	
	istringstream(dat[i].diasing)>> diaentero;
	istringstream(dat[i].mesing)>> mesentero;
	istringstream(dat[i].anioing)>> anioentero;
	
	float totalInicio = (mesentero * 30) + diaentero;
	float totalActual = 360;
	
	int TotalDias = totalActual - totalInicio;
	
	
	int cantidadAnios,cantidadMeses,CantidadDias;
	
	cantidadAnios = trunc(TotalDias/360); 
    cantidadMeses = trunc((TotalDias-cantidadAnios)/30);
    CantidadDias = trunc(TotalDias-(cantidadMeses*30));
	
	
	sal_total_meses=(dat[i].aux2.salariobruto/12)*cantidadMeses;
	sal_total_dias=(((dat[i].aux2.salariobruto/12)/30)*CantidadDias);
	
	dat[i].aux2.aguinaldo=sal_total_meses +sal_total_dias;
	return dat[i].aux2.aguinaldo;
	
		//if(dat[i].diasing=30 && dat[i].mesing=11){
			
		//}
	}
	
}


float subsidioINSS(int q4){
	

		for(i=q4;i<2;i++){
		
			if(dat[i].aux2.subsidiodia<4){
			dat[i].aux2.subsidio=0;
			return dat[i].aux2.subsidiodia;
				}
		else{
		
		dat[i].aux2.subsidio=(dat[i].aux2.salariobruto/30)*dat[i].aux2.subsidiodia;
		return dat[i].aux2.subsidio;
		
			}
				
		}
	}

float IR(int q9){
	float p,p1,p3,p4,p6,p5,p7;
	for(i=q9;i<2;i++){
	
		p=0;p1=0;p3=0;p4=0;p5=0;p6=0;p7=0;
			
		p=dat[i].aux2.salariobruto*12;
		p1=p*0.0625;
		p3=p-p1;
		
		if(p3>=0.01 && p3<=100000){
			dat[i].aux2.aux1.IR_deu=0;
			return dat[i].aux2.aux1.IR_deu;
		}
		
		
		if(p3>=100000.01 && p3<=200000){
			p4=p3-100000;
			p5=p4*0.15;
			dat[i].aux2.aux1.IR_deu=p5/12;
			return dat[i].aux2.aux1.IR_deu;
		}
		
		
		if(p3>=200000.01 && p3<=350000){
			p4=p3-200000;
			p5=p4*0.2;
			p6=p5+15000;
			dat[i].aux2.aux1.IR_deu=p6/12;
			return dat[i].aux2.aux1.IR_deu;
		}
		if(p3>=350000.01 && p3<=500000){
			p4=p3-350000;
			p5=p4*0.25;
			p6=p5+45000;
			dat[i].aux2.aux1.IR_deu=p6/12;
			return dat[i].aux2.aux1.IR_deu;
		}
		if(p3>=500000.01){
			p4=p3-500000;
			p5=p4*0.3;
			p6=p5+82500;
			dat[i].aux2.aux1.IR_deu=p6/12;
			return dat[i].aux2.aux1.IR_deu;
		}
		
	}
}


float IngresosTotal(int q7){
	
	for(i=q7;i<2;i++){
		dat[i].aux2.totalingresos=dat[i].aux2.salarioing + dat[i].aux2.horasmonto + dat[i].aux2.feriados + dat[i].aux2.subsidio + dat[i].aux2.aguinaldo;
		return dat[i].aux2.totalingresos;
	}
}

float deduccionesTotal(int q10){
	
	for(i=q10;i<2;i++){
		dat[i].aux2.aux1.totaldeducciones= dat[i].aux2.aux1.INSS_deu + dat[i].aux2.aux1.IR_deu + dat[i].aux2.aux1.anticiposS +dat[i].aux2.aux1.otrosDescuentos;
		return dat[i].aux2.aux1.totaldeducciones;
	}
	
}

float aPagar(int q11){
	
	for(i=q11;i<2;i++){
		dat[i].aux2.aux1.PagaTotal= dat[i].aux2.totalingresos - dat[i].aux2.aux1.totaldeducciones;
		return dat[i].aux2.aux1.PagaTotal;
	}
}
