FROM ubuntu:22.04
RUN apt-get update && apt-get install -y nano && rm -rf /var/lib/apt/lists/*
COPY sk_new.sh /usr/local/bin/sk_new.sh
RUN chmod +x /usr/local/bin/sk_new.sh
CMD ["/bin/bash"]
