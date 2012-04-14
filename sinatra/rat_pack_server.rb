require 'sinatra'
require 'json'

class RatPackServer < Sinatra::Application
  @@activated=0
  get '/' do
    haml :index, :locals => {:activated => @@activated, :indicator_class => indicator(@@activated)}
  end
  get '/status.json' do
    "{\"activated\": #{@@activated}}"
  end
  put '/status.json' do
    request.body.rewind  # in case someone already read it
    data = JSON.parse request.body.read
    @@activated = data['activated']
    "{\"activated\": #{@@activated}}"
  end
  def indicator(state)
    if(state == 0)
      :off
    else
      :on
    end
  end
end