require 'sinatra'
require 'json'

class RatPackServer < Sinatra::Application
  configure do
    set :activated, 0
  end
  get '/' do
    haml :index, :locals => {:activated => settings.activated, :indicator_class => indicator(settings.activated)}
  end
  get '/status.json' do
    "{\"activated\": #{settings.activated}}"
  end
  put '/status.json' do
    request.body.rewind  # in case someone already read it
    data = JSON.parse request.body.read
    settings.activated = data['activated']
    puts "********** data: #{data}"
    puts "********** {\"activated\": #{settings.activated}}"
    "{\"activated\": #{settings.activated}}"
  end
  def indicator(state)
    if(state == 0)
      :off
    else
      :on
    end
  end
end