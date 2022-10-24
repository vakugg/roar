TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        lfsr.c \
        main.c \
        sorteer.c

DISTFILES += \
    find_assembler.s
#обезьянка видит - обезьянка повторяет. Гайдлайнов нет, а свой файл я не
#смог добавить, так он в заголовочных и остался валяться

# переменная для исходных файлов
ASM += find_assembler.s

# Просто описание компилятора,
# не несет функциональной нагрузки.
masm.name = GNU AS compiler

# Имя переменной для исходных файлов.
# Для каждого из них будет сформировано
# правило в Makefile
masm.input = ASM

# Имя исходящего файла.
# Имя цели в правиле будет иметь именно этот вид.
# Что такое ${QMAKE_FILE_BASE} - ниже.
masm.output = ${QMAKE_FILE_BASE}.o

# команды для формирования исходящего файла
# в данном случае - вызов MASM 32bit
masm.commands = as -o ${QMAKE_FILE_OUT} ${QMAKE_FILE_IN}

# добавляем компилятор в список препроцессоров
QMAKE_EXTRA_COMPILERS += masm

HEADERS += \
    compiler-gcc4.h \
    compiler.h \
    instructions.h \
    lfsr.h \
    sorteer.h
