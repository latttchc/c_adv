
MAC OSで作成しているためVScodeでコードを作成しています。(Shift JISでは文字化けしてしまうため)
そのためこのソースコードを読み取るには以下の方法が必要です。

エンコードはUTF-8で作成しているためダウンロードファイルをMACのターミナル上で以下のコマンドを入力する
コマンド：iconv -f SHIFT_JIS -t UTF-8 kadaiLAST.txt > kadaiLAST_utf8.txt

あるいは送付してあるkadaiLAST_utf8.txtを読み込む必要があります。

※また本コードはfopen("kadaiLAST_utf8.txt", "r");の記述をしているのでkadaiLASTは読み込めません。

工夫点:

while (i < MAX_QNUM && fgets(quiz[i].q, sizeof(quiz[i].q), fp) != NULL)を入れることで出力での段落がずれる問題を、ファイルから問題内容を読み取ってから問題選択肢を読み取ることで段落がずれる問題を解消しました。