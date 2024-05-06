project(
    'interruptkeyboard',
    'c',
    meson_version: '>=1.3.0',
    default_options: ['c_std=c17'],
)

interruptkeyboard_src = []
interruptkeyboard_includes = []

subdir('src')

interruptkeyboard = executable(
    'interruptkeyboard',
    interruptkeyboard_src,
    include_directories: interruptkeyboard_includes,
)

prog_objcopy = find_program('objcopy')

input_bfdname = meson.get_external_property('input_bfdname')

custom_target(
    'interruptkeyboard_srecord',
    build_by_default: true,
    output: 'interruptkeyboard.s19',
    input: interruptkeyboard,
    command: [
        prog_objcopy,
        '-I' + input_bfdname,
        '@INPUT@',
        '-Osrec', '@OUTPUT@',
    ],
)
