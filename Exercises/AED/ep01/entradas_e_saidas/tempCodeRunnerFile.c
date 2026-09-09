 if (argc < 3) {
        printf("Uso do comando eh: %s arquivo_entrada.txt arquivo_saida.txt\n", argv[0]);
        return 1;
    }
    
    FILE* entrada = fopen(argv[1], "r");
    FILE* saida = freopen(argv[2], "w", stdout);

    if (!entrada || !saida) {
        fprintf(stderr, "Erro ao tentar abrir os arquivos.\n");
        return 1;
    }
