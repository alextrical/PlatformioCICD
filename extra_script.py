Import("env")
env.Replace(PROGNAME="firmware_%s" % env.GetProjectOption("custom_prog_version") + "_" + env["PIOENV"])