#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record{
	
	char *nome, *autor;
};


int main(){
	
	int choice;
	void function_film(void);
	void function_music(void);

	system("clear || cls");
	printf("\t\t\tDigite uma opção:\n");
	printf("\t\t\t[1]Para filmes\n");
	printf("\t\t\t[2]Para Músicas\n");
	printf("\t\t\t[3]Para Sair\n\t\t\t ");
	scanf("  %i", &choice);
	
	switch(choice)
	{
		case 1:
			system("clear");
			function_film();


		break;

		case 2:

			system("clear");
			function_music();
	
		break;

    case 3:
    exit(1);
    break;

	}
		
	return 0;
}


void function_film(void){

	int choice, sn;
	int posicao = 0;
	int count = 0;
	FILE *file_escrita;
	file_escrita = fopen("bin/file.bin", "ab");
	struct record *dados = (struct record *)malloc(sizeof(struct record));
	dados->nome = (char *)malloc(50*sizeof(char));
	dados->autor = (char *)malloc(50*sizeof(char));
	FILE *file_leitura;
	file_leitura = fopen("bin/file.bin", "rb");
	FILE *file_alteracao;
	file_alteracao = fopen("bin/file_alt.bin", "ab");

	if(file_escrita == NULL){
		printf("Arquivo não pode ser aberto\n");
		exit(1);
	}

	if(file_leitura == NULL){
		printf("Arquivo não pode ser aberto\n");
		exit(1);
	}

	if(file_alteracao == NULL){
		printf("Arquivo não pode ser aberto\n");
		exit (1);
	}

	printf("\t\t\tDigite a opção que deseja:\n\n");
	printf("\t\t\t[1]Para Incluir.\n");
	printf("\t\t\t[2]Para Vizualisar.\n");
	printf("\t\t\t[3]Para Alterar.\n");
	printf("\t\t\t[4]Para Excluir.\n");
	printf("\t\t\t[5]Para Voltar.\n\t\t\t ");
	scanf(" %i", &choice);

	switch(choice)
	{
		case 1:
			system("clear");
			printf("Digite o nome do filme:");
			scanf(" %[^\n]s", dados->nome);
			printf("Digite o nome do diretor:");
			scanf(" %[^\n]s", dados->autor);
			fwrite(dados->nome, 50, 1, file_escrita);
			fwrite(dados->autor, 50, 1, file_escrita);
			fclose(file_escrita);
			
			printf("\t\t\tDeseja voltar?[1]SIM[0]NÃO\n\t\t\t");
			scanf(" %i", &sn);
			if (sn == 1){
			system("clear");
			function_film();
			}else
				exit(1);
			

		break;

		case 2:

			system("clear");
			while(! feof(file_leitura))
			{
				fread(dados->nome, 50, 1, file_leitura);
				fread(dados->autor, 50, 1, file_leitura);
				if (!feof(file_leitura))
				{
					printf("%i\n", count);
					printf("%s\n", dados->nome);
					printf("%s\n", dados->autor);
				}

				count = count + 1;
			}

			fclose(file_leitura);

			printf("\t\t\tDeseja voltar?[1]SIM[0]NÃO\n\t\t\t");
			scanf(" %i", &sn);
			if (sn == 1){
			system("clear");
			function_film();
			}else
				exit(1);
			



		break;

		case 3:
			
			system("clear");
			printf("Digite a posição que deseja alterar:\n");
			scanf(" %i", &posicao );
			while (! feof(file_leitura))
			{
				fread(dados->nome,50,1,file_leitura);
				fread(dados->autor,50,1,file_leitura);
				if (count == posicao){
					
					system("clear");
					printf("\t\t\t%s\n", dados->nome);
					printf("\t\t\t%s\n", dados->autor);
					
				}

				count = count + 1;
			}
			
			rewind(file_leitura);
			
			count = 0;
			while (!feof(file_leitura))
			{ 
				
				fread(dados->nome,50,1,file_leitura);
				fread(dados->autor,50,1,file_leitura);
				if (count != posicao && (!feof(file_leitura))) 
				{
				fwrite(dados->nome, 50, 1, file_alteracao);
				fwrite(dados->autor, 50, 1, file_alteracao);

				}
					count = count + 1;
			}  
			

			printf("Digite o novo nome do filme:\n");
			scanf(" %[^\n]s", dados->nome);
			printf("Digite o nome do diretor:\n");
			scanf(" %[^\n]s", dados->autor);
			fwrite(dados->nome, 50, 1, file_alteracao);
			fwrite(dados->autor, 50, 1, file_alteracao);


			fclose(file_escrita);
			fclose(file_alteracao);
			fclose(file_leitura);	
			remove("bin/file.bin");
			rename("bin/file_alt.bin" ,"bin/file.bin");		


			printf("\t\t\tDeseja voltar?[1]SIM[0]NÃO\n\t\t\t");
			scanf(" %i", &sn);
			if (sn == 1){
			system("clear");
			function_film();
			}else
				exit(1);
			

		break;

		case 4:

			system("clear");
			printf("Digite a posição que deseja excluir:\n");
			scanf(" %i", &posicao );
			while (! feof(file_leitura))
			{
				fread(dados->nome,50,1,file_leitura);
				fread(dados->autor,50,1,file_leitura);
				if (count == posicao){
					
					system("clear");
					printf("\t\t\t%s\n", dados->nome);
					printf("\t\t\t%s\n", dados->autor);
					
				}

				count = count + 1;
			}

			rewind(file_leitura);
			
			count = 0;
			while (!feof(file_leitura))
			{ 
				
				fread(dados->nome,50,1,file_leitura);
				fread(dados->autor,50,1,file_leitura);
				if (count != posicao && (!feof(file_leitura))) 
				{
				fwrite(dados->nome, 50, 1, file_alteracao);
				fwrite(dados->autor, 50, 1, file_alteracao);

				}
					count = count + 1;
			}  
			
			fclose(file_escrita);
			fclose(file_alteracao);
			fclose(file_leitura);	
			remove("bin/file.bin");
			rename("bin/file_alt.bin" ,"bin/file.bin");		

			printf("\t\t\tDeseja voltar?[1]SIM[0]NÃO\n\t\t\t");
			scanf(" %i", &sn);
			if (sn == 1){
			system("clear");
			function_film();
			}else
				exit(1);
			
		break;

		case 5:

		system("./project");

		break;
	}


}





void function_music(void){

	int choice, sn;
	int posicao = 0;
	int count = 0;
	FILE *file_escrita_music;
	file_escrita_music = fopen("bin/music.bin", "ab");
	struct record *dados = (struct record *)malloc(sizeof(struct record));
	dados->nome = (char *)malloc(50*sizeof(char));
	dados->autor = (char *)malloc(50*sizeof(char));
	FILE *file_leitura_music;
	file_leitura_music = fopen("bin/music.bin", "rb");
	FILE *file_alteracao_music;
	file_alteracao_music = fopen("bin/alt_music.bin", "ab");

	if(file_escrita_music == NULL){
		printf("Arquivo não pode ser aberto\n");
		exit(1);
	}

	if(file_leitura_music == NULL){
		printf("Arquivo não pode ser aberto\n");
		exit(1);
	}

	if(file_alteracao_music == NULL){
		printf("Arquivo não pode ser aberto\n");
		exit (1);
	}

	printf("\t\t\tDigite a opção que deseja:\n\n");
	printf("\t\t\t[1]Para Incluir.\n");
	printf("\t\t\t[2]Para Vizualisar.\n");
	printf("\t\t\t[3]Para Alterar.\n");
	printf("\t\t\t[4]Para Excluir.\n");
	printf("\t\t\t[5]Para Voltar.\n\t\t\t ");
	scanf(" %i", &choice);

	switch(choice)
	{
		case 1:
			system("clear");
			printf("Digite o nome da musica:");
			scanf(" %[^\n]s", dados->nome);
			printf("Digite o nome do compositor:");
			scanf(" %[^\n]s", dados->autor);
			fwrite(dados->nome, 50, 1, file_escrita_music);
			fwrite(dados->autor, 50, 1, file_escrita_music);
			fclose(file_escrita_music);
			
			printf("\t\t\tDeseja voltar?[1]SIM[0]NÃO\n\t\t\t");
			scanf(" %i", &sn);
			if (sn == 1){
			system("clear");
			function_music();
			}else
				exit(1);
			

		break;

		case 2:

			system("clear");
			while(! feof(file_leitura_music))
			{
				fread(dados->nome, 50, 1, file_leitura_music);
				fread(dados->autor, 50, 1, file_leitura_music);
				if (!feof(file_leitura_music))
				{
					printf("%i\n", count);
					printf("%s\n", dados->nome);
					printf("%s\n", dados->autor);
				}

				count = count + 1;
			}

			fclose(file_leitura_music);

			printf("\t\t\tDeseja voltar?[1]SIM[0]NÃO\n\t\t\t");
			scanf(" %i", &sn);
			if (sn == 1){
			system("clear");
			function_music();
			}else
				exit(1);
			



		break;

		case 3:
			
			system("clear");
			printf("Digite a posição que deseja alterar:\n");
			scanf(" %i", &posicao );
			while (! feof(file_leitura_music))
			{
				fread(dados->nome,50,1,file_leitura_music);
				fread(dados->autor,50,1,file_leitura_music);
				if (count == posicao){
					
					system("clear");
					printf("\t\t\t%s\n", dados->nome);
					printf("\t\t\t%s\n", dados->autor);
					
				}

				count = count + 1;
			}
			
			rewind(file_leitura_music);
			
			count = 0;
			while (!feof(file_leitura_music))
			{ 
				
				fread(dados->nome,50,1,file_leitura_music);
				fread(dados->autor,50,1,file_leitura_music);
				if (count != posicao && (!feof(file_leitura_music))) 
				{
				fwrite(dados->nome, 50, 1, file_alteracao_music);
				fwrite(dados->autor, 50, 1, file_alteracao_music);

				}
					count = count + 1;
			}  
			

			printf("Digite nome da nova música:\n");
			scanf(" %[^\n]s", dados->nome);
			printf("Digite o nome do compositor:\n");
			scanf(" %[^\n]s", dados->autor);
			fwrite(dados->nome, 50, 1, file_alteracao_music);
			fwrite(dados->autor, 50, 1, file_alteracao_music);


			fclose(file_escrita_music);
			fclose(file_alteracao_music);
			fclose(file_leitura_music);	
			remove("bin/music.bin");
			rename("bin/alt_music.bin", "bin/music.bin");		


			printf("\t\t\tDeseja voltar?[1]SIM[0]NÃO\n\t\t\t");
			scanf(" %i", &sn);
			if (sn == 1){
			system("clear");
			function_music();
			}else
				exit(1);
			

		break;

		case 4:

			system("clear");
			printf("Digite a posição que deseja excluir:\n");
			scanf(" %i", &posicao );
			while (! feof(file_leitura_music))
			{
				fread(dados->nome,50,1,file_leitura_music);
				fread(dados->autor,50,1,file_leitura_music);
				if (count == posicao){
					
					system("clear");
					printf("\t\t\t%s\n", dados->nome);
					printf("\t\t\t%s\n", dados->autor);
					
				}

				count = count + 1;
			}

			rewind(file_leitura_music);
			
			count = 0;
			while (!feof(file_leitura_music))
			{ 
				
				fread(dados->nome,50,1,file_leitura_music);
				fread(dados->autor,50,1,file_leitura_music);
				if (count != posicao && (!feof(file_leitura_music))) 
				{
				fwrite(dados->nome, 50, 1, file_alteracao_music);
				fwrite(dados->autor, 50, 1, file_alteracao_music);

				}
					count = count + 1;
			}  
			
			fclose(file_escrita_music);
			fclose(file_alteracao_music);
			fclose(file_leitura_music);	
			remove("bin/music.bin");
			rename("bin/alt_music.bin", "bin/music.bin");		



			printf("\t\t\tDeseja voltar?[1]SIM[0]NÃO\n\t\t\t");
			scanf(" %i", &sn);
			if (sn == 1){
			system("clear");
			function_music();
			}else
				exit(1);
			
		break;

		case 5:

		system("./project");

		break;
	}


}


















