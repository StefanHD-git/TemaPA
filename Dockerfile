FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    gcc \
    g++ \
    make \
    cmake \
    git \
    valgrind \
    wget \
    curl \
    ca-certificates \
    libpcre3-dev \
    && rm -rf /var/lib/apt/lists/*

RUN wget https://go.dev/dl/go1.24.0.linux-amd64.tar.gz && \
    tar -C /usr/local -xzf go1.24.0.linux-amd64.tar.gz && \
    rm go1.24.0.linux-amd64.tar.gz

RUN wget https://github.com/danmar/cppcheck/archive/refs/tags/2.13.0.tar.gz && \
    tar -xzf 2.13.0.tar.gz && \
    cd cppcheck-2.13.0 && \
    mkdir build && cd build && \
    cmake .. && \
    make -j$(nproc) install && \
    cd ../.. && rm -rf cppcheck-2.13.0 2.13.0.tar.gz

ENV PATH=/usr/local/go/bin:/usr/local/bin:$PATH
ENV GOPATH=/go
ENV PATH=$PATH:$GOPATH/bin

WORKDIR /usr/src/app

CMD ["/bin/bash"]