#!/bin/bash

CHECKER=./checker_linux
PUSH_SWAP=./push_swap

COUNT=10      # Número de testes
NUMBERS=10   # Quantidade de números na entrada

echo "🏁 Testando push_swap com $NUMBERS números, $COUNT vezes..."

for i in $(seq 1 $COUNT); do
    echo ""
    echo "🔹 Teste $i:"
    
    # Gera entrada aleatória
    ARG=$(shuf -i 1-$NUMBERS -n $NUMBERS | tr '\n' ' ')
    echo "📥 Entrada: $ARG"

    # Executa push_swap e salva as instruções
    OUTPUT=$($PUSH_SWAP $ARG)
    OPS=$(echo "$OUTPUT" | wc -l)

    # Roda checker com a saída
    RESULT=$(echo "$OUTPUT" | $CHECKER $ARG)

    # Mostra a saída do push_swap (pode comentar se quiser menos verboso)
    echo -e "📤 Instruções:\n$OUTPUT"

    # Mostra o resultado
    if [ "$RESULT" = "OK" ]; then
        echo "✅ Resultado: $RESULT"
    elif [ "$RESULT" = "KO" ]; then
        echo "❌ Resultado: $RESULT (ordenação falhou)"
    else
        echo "⚠️ Resultado: ERRO - $RESULT"
    fi

    echo "🔢 Operações usadas: $OPS"
    echo "-----------------------------"
done