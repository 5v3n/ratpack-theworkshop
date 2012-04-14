require './sinatra/rat_pack_server.rb'

use Rack::ShowExceptions

run RatPackServer.new