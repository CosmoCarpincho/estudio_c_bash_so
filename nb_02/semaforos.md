# Semaforos

wait: comprueba el valor del semáforo, si es negativo o cero el proceso se suspende sin consumir recursos hasta que el valor deje de ser negativo. Si el valor es positivo el proceso o hilo, sigue ejecutándose y se decrementa en una unidad el valor del semaforo.

signal: esta función incrementa el valor del semáforo, este comportamiento debe realizarse cuando se hag salido de la zona de exclusión mutua.
