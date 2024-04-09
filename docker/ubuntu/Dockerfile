ARG TAG=22.04
FROM ubuntu:${TAG}

ENV TZ=US/Michigan

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y \
        ccache \
        g++ \
        git \
        make \
        ninja-build \
        curl \
        tree \
        dpkg-dev \
        valgrind \
        zip \
        file \
        && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Install cmake
# Install cmake
ARG TARGETPLATFORM
RUN case "${TARGETPLATFORM}" in \
         "linux/amd64")  ARCHITECTURE="x86_64"   ;; \
         "linux/arm64")  ARCHITECTURE="aarch64"  ;; \
         *)  exit 1 ;; \
    esac; \
    curl --insecure -L "https://github.com/Kitware/CMake/releases/download/v3.29.0/cmake-3.29.0-linux-${ARCHITECTURE}.tar.gz" | tar xz --strip-components=1 -C /usr/local
# RUN apt-get update && \
#     apt-get install gpg wget --no-install-recommends -y && \
#     wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | gpg --dearmor - | tee /usr/share/keyrings/kitware-archive-keyring.gpg >/dev/null && \
#     echo 'deb [signed-by=/usr/share/keyrings/kitware-archive-keyring.gpg] https://apt.kitware.com/ubuntu/ jammy main' | tee /etc/apt/sources.list.d/kitware.list >/dev/null && \
#     apt-get update && \
#     rm /usr/share/keyrings/kitware-archive-keyring.gpg && \
#     apt-get install kitware-archive-keyring && \
#     apt-get update && \
#     apt-get upgrade -y && \
#     apt-get install cmake --no-install-recommends -y && \
#     rm -rf /var/lib/apt/lists/*

# Put ccache into the path
ENV PATH /usr/lib/ccache:$PATH
RUN export PATH=/usr/lib/ccache/:$PATH
