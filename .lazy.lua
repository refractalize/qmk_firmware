return {
  {
    "refractalize/runtest.nvim",

    opts = {
      filetypes = {
        c = "qmk",
      },
      runners = {
        qmk = {
          name = "QMK",
          commands = {
            line = function()
              local buffer = vim.api.nvim_get_current_buf()
              local filename = vim.fn.expand("%:.")
              local path_components = vim.split(filename, "/")
              local keyboards, manufacturer, keyboard_name, keymaps, keymap = unpack(path_components)
              if keyboards ~= "keyboards" or keymaps ~= "keymaps" then
                error("Expected path to be in the format keyboards/<manufacturer>/<keyboard_name>/keymaps/<keymap>/...")
              end
              local keyboard = manufacturer .. "/" .. keyboard_name
              return {
                run_spec = function(runner_config)
                  return { { "qmk", "flash", "-kb", keyboard, "-km", keymap } }
                end,
              }
            end,
          },
        },
      },
    },
  },
}
