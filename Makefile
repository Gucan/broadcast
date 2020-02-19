default: build
build:
	@echo "  CC\tsend"
	@$(CROSS_COMPILE)gcc send.c -o send $(CFLAGS) $(LDFLAGS)
	@echo "  CC\trecv"
	@$(CROSS_COMPILE)gcc recv.c -o recv $(CFLAGS) $(LDFLAGS)
	@echo "  STRIP\tsend"
	@$(CROSS_COMPILE)strip send
	@echo "  STRIP\trecv"
	@$(CROSS_COMPILE)strip recv
clean:
	@echo "  CLEAN\tsend\n  CLEAN\trecv"
	@rm send recv
