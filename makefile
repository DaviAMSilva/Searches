DIRS	:= build/ lib/
SOURCES	:= $(wildcard source/*.c)
OBJECTS	:= $(patsubst source/%.c,build/%.o,$(SOURCES))
LIBS	:= $(patsubst source/%.c,lib/lib%.a,$(SOURCES))





all: $(LIBS) lib/libsearches.a
dirs: $(DIRS)

.PHONY: all dirs clean
.SECONDARY: $(OBJECTS)





build/%.o: source/%.c | $(DIRS)
	gcc -c $^ -Wall -O3 -o $@ -I include/

lib/lib%.a: build/%.o | $(DIRS)
	ar cr $@ $^

lib/libsearches.a: $(OBJECTS)
	ar cr $@ $^





$(DIRS):
	@mkdir -p $@

clean:
	rm -fr build/ lib/