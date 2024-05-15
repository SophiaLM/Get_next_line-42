#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int     main()
{
	char	buffer[25];
	int	bytes = 1;
        int     fd = open("texto.txt", O_RDONLY);

        while (bytes > 0)
        {
                bytes = read(fd, buffer, 5);
		buffer[bytes] = '\0';
		printf("%s\n", buffer);
        //        printf("%d\n", bytes);
        }
}

/*
 	PARA EL PRINT DE BYTES:
Iteración 1: Lee los primeros 5 bytes del archivo: "12345". Quedan "67890\n1234567890\n1234567890\n". return 5
Iteración 2: Lee los siguientes 5 bytes: "67890". Quedan "\n1234567890\n1234567890\n". return 5
Iteración 3: Lee los siguientes 5 bytes: "\n1234". Quedan "567890\n1234567890\n". return 5
Iteración 4: Lee los siguientes 5 bytes: "56789". Quedan "0\n1234567890\n". return 5
Iteración 5: Lee los siguientes 5 bytes: "0\n123". Quedan "4567890\n". return 5
Iteración 6: Lee los siguientes 5 bytes: "45678". Quedan "90\n". return 5
Iteración 7: Lee los siguientes 5 bytes: "90\n". return 3
*/
