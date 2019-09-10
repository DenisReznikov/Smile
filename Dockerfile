FROM denisreznikov/qtdoc
RUN  mkdir denis
RUN  cd denis
RUN  git clone --depth=50 --branch=master https://github.com/DenisReznikov/Smile.git DenisReznikov/Smile
RUN  cd DenisReznikov/Smile/Smile
RUN  qmake
RUN  make
