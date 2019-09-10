FROM denisreznikov/qtdoc
RUN  mkdir denis
RUN  cd denis
RUN  git clone --depth=50 --branch=master https://github.com/DenisReznikov/Smile.git Denis/Smile
RUN  cd Denis/Smile/Smile && ls && qmake Smile.pro && make
