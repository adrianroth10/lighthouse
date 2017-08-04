data, header = readdlm(ARGS[1], '\t', String, '\n', header=true)

dates = map(x -> DateTime(x, "mm-dd"), data[:, 1])
dates = map(Dates.datetime2epochms, dates) / 1000 / 3600 / 24 - 365
dates = reshape(dates, length(dates), 1)
times = map(x -> DateTime(x, "HH-MM"), data[:, 2:3])
times = map(Dates.datetime2epochms, times) / 1000 - 3.16224e7 # normalizing the epoch
sunrise = times[:, 1:1]
sunset = times[:, 2:2]

X = hcat(ones(length(dates)), dates, dates.^2)
a1 = (X' * X) \ X' * sunrise
a2 = (X' * X) \ X' * sunset
writedlm(string(ARGS[1], "_out"), vcat(a1, a2))

# input as days and output as seconds for sunrise and sunset
